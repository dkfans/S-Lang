/* Exception Handling */
/*
Copyright (C) 2004, 2005, 2006 John E. Davis

This file is part of the S-Lang Library.

The S-Lang Library is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The S-Lang Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
USA.  
*/
#define _GNU_SOURCE
#include "slinclud.h"

#include "slang.h"

#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif

#include "_slang.h"

static SLang_Object_Type *Object_Thrownp = NULL;
static SLang_Object_Type Object_Thrown;
static char *File_With_Error = NULL;
static char *Function_With_Error = NULL;
static char *Last_Function_With_Error = NULL;   /* either slstring or "<top-level>" */

static int Linenum_With_Error = -1;

static void free_thrown_object (void)
{
   if (Object_Thrownp != NULL)
     {
	SLang_free_object (Object_Thrownp);
	Object_Thrownp = NULL;
     }
}


typedef struct Error_Context_Type
{
   int err;
   int err_cleared;
   int linenum;
   char *file;
   char *function;
   struct Error_Context_Type *next;
}
Error_Context_Type;

static Error_Context_Type *Error_Context;

int _pSLang_push_error_context (void)
{
   Error_Context_Type *c;
   if (NULL == (c = (Error_Context_Type *)SLmalloc (sizeof (Error_Context_Type))))
     return -1;
   
   c->next = Error_Context;
   c->err = _pSLang_Error;
   c->err_cleared = 0;
   c->file = File_With_Error;
   c->linenum = Linenum_With_Error;
   c->function = Function_With_Error;

   File_With_Error = NULL;
   Linenum_With_Error = -1;

   Error_Context = c;
   SLKeyBoard_Quit = 0;
   if (-1 == SLang_set_error (0))
     {
	_pSLang_pop_error_context ();
	return -1;
     }
   return 0;
}

int _pSLang_pop_error_context (void)
{
   Error_Context_Type *e;

   e = Error_Context;
   if (e == NULL)
     return -1;
   
   Error_Context = e->next;

   if (_pSLang_Error == 0)
     {
	if (e->err_cleared == 0)
	  {
	     File_With_Error = e->file; e->file = NULL;
	     Linenum_With_Error = e->linenum;
	     Function_With_Error = e->function; e->function = NULL;
	     (void) SLang_set_error (e->err);
	  }
     }

   if (_pSLang_Error == SL_UserBreak_Error)
     SLKeyBoard_Quit = 1;
   
   SLang_free_slstring (e->file);
   SLfree ((char *) e);
   return 0;
}

int _pSLerr_get_last_error (void)
{
   Error_Context_Type *e;

   e = Error_Context;
   if (e == NULL)
     return 0;
   return e->err;
}

static void do_file_line_funct_error (char *file, int linenum, char *function)
{
   if ((file == NULL) || (_pSLang_Error == 0))
     return;
   
   if (Last_Function_With_Error == function)	       /* either slstring or "<top-level>" */
     return;
   Last_Function_With_Error = function;
   if (*function)
     _pSLerr_traceback_msg ("%s:%d:%s:%s\n", file, linenum, function, SLerr_strerror (_pSLang_Error));
}

int _pSLerr_set_line_info (char *file, int linenum, char *fun)
{
   if (linenum == 0)
     linenum = -1;

   if (SLang_Traceback == 0)
     {
	if ((File_With_Error != NULL) && (Linenum_With_Error != -1))
	  return 0;
	if ((linenum == -1) && (file == NULL))
	  return 0;
     }

   if (fun == NULL)
     fun = "<top-level>";

   do_file_line_funct_error (file, linenum, fun);

   if (File_With_Error != NULL)
     return 0;

   Linenum_With_Error = linenum;
   if (file != NULL)
     {
	if (NULL == (file = SLang_create_slstring (file)))
	  return -1;
     }
   if (NULL == (fun = SLang_create_slstring (fun)))
     {
	SLang_free_slstring (file);    /* NULL ok */
	return -1;
     }

   File_With_Error = file;
   Function_With_Error = fun;
   
#if SLANG_HAS_BOSEOS && SLANG_HAS_DEBUGGER_SUPPORT
   (void) _pSLcall_debug_hook (file, linenum);
#endif

   return 0;
}

static int _pSLerr_get_last_error_line_info (char **filep, int *linep, char **funp)
{
   Error_Context_Type *e = Error_Context;
   if (e == NULL)
     {
	*filep = NULL;
	*linep = -1;
	*funp = NULL;
	return -1;
     }
   *filep = e->file;
   *linep = e->linenum;
   *funp = e->function;
   return 0;
}

   
void (*SLang_User_Clear_Error)(void);
void _pSLerr_clear_error (void)
{
   SLang_set_error (0);
   free_thrown_object ();
   if (Error_Context != NULL)
     Error_Context->err_cleared = 1;
   SLang_free_slstring (File_With_Error); File_With_Error = NULL;
   SLang_free_slstring (Function_With_Error); Function_With_Error = NULL;
   Linenum_With_Error = -1;
   Last_Function_With_Error = NULL;
   if (SLang_User_Clear_Error != NULL) (*SLang_User_Clear_Error)();
   _pSLerr_free_queued_messages ();
}

int _pSLerr_throw (void)
{
   int e;
   int nargs = SLang_Num_Function_Args;
   char *msg = NULL;

   free_thrown_object ();

   switch (nargs)
     {
      case 3:
	if (-1 == SLang_pop (&Object_Thrown))
	  return -1;
	Object_Thrownp = &Object_Thrown;
	/* drop */
      case 2:
	if (-1 == SLang_pop_slstring (&msg))
	  {
	     free_thrown_object ();
	     return -1;
	  }
      case 1:
	/* drop */
	if (-1 == _pSLerr_pop_exception (&e))
	  {
	     SLang_free_slstring (msg);/* NULL ok */
	     free_thrown_object ();
	     return -1;
	  }
	break;
	
      default:
	SLang_verror (SL_NumArgs_Error, "expecting: throw error [, optional-message [, optional-arg]]");
	return -1;
     }
   
   if (msg != NULL)
     {
	SLang_verror (e, "%s", msg);
	SLang_free_slstring (msg);
     }
   else
     SLang_set_error (e);
   
   return 0;
}

#if SLANG_VERSION >= 20100
int SLerr_throw (int err, char *msg, SLtype obj_type, VOID_STAR objptr)
{
   free_thrown_object ();

   if ((obj_type != 0) || (objptr != NULL))
     {
	if (-1 == SLang_push_value (obj_type, objptr))
	  return -1;
	if (-1 == SLang_pop (&Object_Thrown))
	  return -1;
	Object_Thrownp = &Object_Thrown;
     }

   if (msg != NULL)
     SLang_verror (err, "%s", msg);
   else
     SLang_set_error (err);

   return 0;
}
#endif
static void new_exception (char *name, int *baseclass, char *description)
{
   (void) SLerr_new_exception (*baseclass, name, description);
}

static void get_exception_info_intrinsic (void)
{
#define NUM_EXCEPT_FIELDS 7
   static char *field_names[NUM_EXCEPT_FIELDS] =
     {
	"error", "descr", "file", "line", "function", "object", "message"
     };
   SLtype field_types[NUM_EXCEPT_FIELDS];
   VOID_STAR field_values[NUM_EXCEPT_FIELDS];
   int err;
   char *desc;
   char *file;
   char *function;
   char *msg;
   int linenum;

   err = _pSLerr_get_last_error ();
   desc = SLerr_strerror (err);
   (void) _pSLerr_get_last_error_line_info (&file, &linenum, &function);
   
   field_types[0] = SLANG_INT_TYPE;
   field_values[0] = (VOID_STAR) &err;

   field_types[1] = SLANG_STRING_TYPE;
   field_values[1] = (VOID_STAR) &desc;

   field_types[2] = SLANG_STRING_TYPE;
   field_values[2] = (VOID_STAR) &file;
   
   field_types[3] = SLANG_INT_TYPE;
   field_values[3] = (VOID_STAR) &linenum;

   field_types[4] = SLANG_STRING_TYPE;
   field_values[4] = (VOID_STAR) &function;

   if (Object_Thrownp == NULL)
     {
	char *null = NULL;
	field_types[5] = SLANG_NULL_TYPE;
	field_values[5] = (VOID_STAR) &null;
     }
   else
     {
	field_types[5] = Object_Thrownp->data_type;
	field_values[5] = _pSLclass_get_ptr_to_value (_pSLclass_get_class (Object_Thrownp->data_type),
						     Object_Thrownp);
     }
   msg = _pSLerr_get_error_from_queue ();
   if ((msg == NULL) || (*msg == 0))
     msg = desc;
   field_types[6] = SLANG_STRING_TYPE;
   field_values[6] = (VOID_STAR) &msg;

   (void) SLstruct_create_struct (NUM_EXCEPT_FIELDS, field_names, field_types, field_values);
   if (msg != desc) 
     SLang_free_slstring (msg);
   /* (void) SLang_push_integer (_pSLerr_get_last_error ()); */
}

int _pSLerr_pop_exception (int *e)
{
   return SLang_pop_integer (e);
}

static int new_exception_hook (char *name, char *desc, int err_code)
{
   SLang_IConstant_Type *ic;

   (void) desc;
   if (NULL != (ic = (SLang_IConstant_Type *)_pSLlocate_name (name)))
     {
	if ((ic->name_type != SLANG_ICONSTANT)
	    || (ic->value != err_code))
	  {
	     SLang_verror (SL_RunTime_Error, "Exception %s already exists and may not be redefined", name);
	     return -1;
	  }
	return 0;
     }
   
   if (-1 == SLns_add_iconstant (NULL, name, SLANG_INT_TYPE, err_code))
     return -1;
   
   return 0;
}

static SLang_Intrin_Fun_Type Except_Table [] =
{
   MAKE_INTRINSIC_0("__get_exception_info", get_exception_info_intrinsic, SLANG_VOID_TYPE),
   MAKE_INTRINSIC_SIS("new_exception", new_exception, SLANG_VOID_TYPE),
   SLANG_END_INTRIN_FUN_TABLE
};

int _pSLang_init_exceptions (void)
{
   _pSLerr_New_Exception_Hook = new_exception_hook;
   if (-1 == _pSLerr_init_interp_exceptions ())
     return -1;
   
   if (-1 == SLadd_intrin_fun_table(Except_Table, NULL))
     return -1;
   
   return 0;
}

