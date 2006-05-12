/* Perfect hash generated by command line:
 * ./a.out
 */
#ifndef SLCONST
#define SLCONST const
#endif
#define MIN_HASH_VALUE	2
#define MAX_HASH_VALUE	151
#define MIN_KEYWORD_LEN 2
#define MAX_KEYWORD_LEN 11

static SLCONST unsigned char Keyword_Hash_Table [256] =
{
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152,  15, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
   10,  15,  25,  30,  35, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152,   0,   0, 152,   0, 152, 152, 152,   5, 152,   0,   0, 152, 152,   0, 
  152, 152,   0,   0,   0,   0, 152, 152,   0, 152, 152, 152, 152, 152, 152,   5, 
  152,   5,   5,  20,  15,   0,   0,   0,  55,  25, 152,   0,  30,  10,  15,   0, 
   15, 152,   0,   0,   0,  50,   0,   0,   5,  20, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 
  152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152
};

static unsigned char keyword_hash (char *s, unsigned int len)
{
   unsigned int sum;

   sum = len;
   while (len)
     {
	len--;
	sum += (unsigned int) Keyword_Hash_Table [(unsigned char)s[len]];
     }
   return sum;
}

typedef SLCONST struct
{
   char *name;
   unsigned int type;
}
Keyword_Table_Type;

static Keyword_Table_Type Keyword_Table [/* 150 */] =
{
   {"or",	OR_TOKEN},
   {"for",	FOR_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"forever",	FOREVER_TOKEN},
   {"xor",	BXOR_TOKEN},
   {"_for",	_FOR_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"break",	BREAK_TOKEN},
   {"ERROR_BLOCK",	ERRBLK_TOKEN},
   {"do",	DO_TOKEN},
   {"not",	NOT_TOKEN},
   {NULL,0},
   {"EXIT_BLOCK",	EXITBLK_TOKEN},
   {NULL,0},
   {NULL,0},
   {"try",	TRY_TOKEN},
   {NULL,0},
   {NULL,0},
   {"USER_BLOCK0",	USRBLK0_TOKEN},
   {"if",	IF_TOKEN},
   {"mod",	MOD_TOKEN},
   {"case",	CASE_TOKEN},
   {NULL,0},
   {"USER_BLOCK1",	USRBLK1_TOKEN},
   {NULL,0},
   {"pop",	POP_TOKEN},
   {"else",	ELSE_TOKEN},
   {NULL,0},
   {"orelse",	ORELSE_TOKEN},
   {NULL,0},
   {"and",	AND_TOKEN},
   {NULL,0},
   {"__tmp",	TMP_TOKEN},
   {"USER_BLOCK2",	USRBLK2_TOKEN},
   {NULL,0},
   {"!if",	IFNOT_TOKEN},
   {NULL,0},
   {NULL,0},
   {"USER_BLOCK3",	USRBLK3_TOKEN},
   {NULL,0},
   {NULL,0},
   {"loop",	LOOP_TOKEN},
   {NULL,0},
   {"USER_BLOCK4",	USRBLK4_TOKEN},
   {"private",	PRIVATE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"static",	STATIC_TOKEN},
   {"typedef",	TYPEDEF_TOKEN},
   {"shr",	SHR_TOKEN},
   {NULL,0},
   {"throw",	THROW_TOKEN},
   {"define",	DEFINE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"return",	RETURN_TOKEN},
   {"andelse",	ANDELSE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"struct",	STRUCT_TOKEN},
   {NULL,0},
   {"variable",	VARIABLE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"exch",	EXCH_TOKEN},
   {NULL,0},
   {NULL,0},
   {"foreach",	FOREACH_TOKEN},
   {"shl",	SHL_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"using",	USING_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"catch",	CATCH_TOKEN},
   {"switch",	SWITCH_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"while",	WHILE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"finally",	FINALLY_TOKEN},
   {"continue",	CONT_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"do_while",	DOWHILE_TOKEN},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {NULL,0},
   {"public",	PUBLIC_TOKEN},
};

static Keyword_Table_Type *is_keyword (char *str, unsigned int len)
{
   unsigned int hash;
   char *name;
   Keyword_Table_Type *kw;

   if ((len < MIN_KEYWORD_LEN)
       || (len > MAX_KEYWORD_LEN))
     return NULL;

   hash = keyword_hash (str, len);
   if ((hash > MAX_HASH_VALUE) || (hash < MIN_HASH_VALUE))
     return NULL;

   kw = &Keyword_Table[hash - MIN_HASH_VALUE];
   if ((NULL != (name = kw->name))
       && (*str == *name)
       && (0 == strcmp (str, name)))
     return kw;
   return NULL;
}
