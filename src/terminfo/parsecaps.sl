% This file parses an ncurses Caps file, which determines the terminfo
% binary layout.

% Caps file format:
% Column 1: terminfo variable name
% Column 2: terminfo capability name
% Column 3: capability type (boolean, numeric, or string)
% Column 4: termcap capability name
% Column 5: KEY_xxx name, if any, `-' otherwise
% Column 6: value for KEY_xxx name, if any, `-' otherwise
% Column 7: Lead with `Y' if capability should be emitted in termcap
%           translations, `-' otherwise
% Column 8: capability description
% Note: Stop parsing the file when a line contains %%-STOP-HERE-%%

private variable Stop_String = "%%-STOP-HERE-%%";

define read_caps_file (file)
{
   variable fp = fopen (file, "r");
   if (fp == NULL)
     {
	() = fprintf (stderr, "Unable to open %s\n", file);
	exit (1);
     }
   variable lines = fgetslines (fp);
   variable i = wherefirst (1 == array_map (Int_Type, &is_substr, lines, Stop_String));
   if (i != NULL)
     lines = lines[[:i]];

   variable s = struct
     {
	name, ti_cap, type, tc_cap, keyname, keyval, flags, desc
     };

   variable fmt = "%s %s %s %s %s %s %s %[^\n]";
   () = readascii (lines, &s.name, &s.ti_cap, &s.type, &s.tc_cap,
		   &s.keyname, &s.keyval, &s.flags, &s.desc;
		   format=fmt, comment="#");

   return s;
}

private define write_table (fp, s, type, tblname)
{

   variable i = where (s.type == type);
   variable cap = s.tc_cap[i];
   variable comment = s.desc[i];
   variable ofs = [0:length(cap)-1];
   i = array_sort (cap); cap = cap[i]; comment = comment[i]; ofs = ofs[i];

   () = fprintf (fp, "static Tgetstr_Map_Type %s[] = \n{\n", tblname);
   _for i (0, length (cap)-1, 1)
     {
	() = fprintf (fp, "   {\"%s\", %3d\t\tUNTIC_COMMENT(\"%s\")},\n",
		     cap[i], ofs[i], comment[i]);
     }
   () = fprintf (fp, "   {\"%s\", %3d\t\tUNTIC_COMMENT(\"%s\")},\n",
		 "", -1, "NULL");
   () = fprintf (fp, "};\n\n\n");
}

define slsh_main ()
{
   if (__argc != 2)
     {
	() = fprintf (stderr, "Usage: %s Caps-file > outfile\n", __argv[0]);
	exit (1);
     }
   variable s = read_caps_file (__argv[1]);
   variable fp = stdout;

   () = fprintf (stdout, "/* This file was autogenerated using %s */\n\n",
		 strjoin (__argv, " "));

   write_table (fp, s, "str", "Tgetstr_Map");
   write_table (fp, s, "num", "Tgetnum_Map");
   write_table (fp, s, "bool", "Tgetflag_Map");
}
