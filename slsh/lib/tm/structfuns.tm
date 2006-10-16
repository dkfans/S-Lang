\function{struct_filter}
\synopsis{Apply a filter to a struct}
\usage{struct_filter(Struct_Type s, Int_Type i)}
\description
  This function applies the filter \exmp{i} to the fields of a structure
  by performing the operation
#v+
    s.field = s.field[i];
#v-
  on each array field of the structure.  Scalar fields will not be modified.
\seealso{where}
\done

\function{struct_combine}
\synopsis{Combine two or more structures}
\usage{new_s = struct_combine (s1, s2, ...)}
\description
  This function creates a new structure from two or more structures
  \exmp{s1}, \exmp{s2},....  The new structure will have fields formed by the
  union of the fields of the input structures.  The new structure fields will
  be given values that correspond to the fields of the input structures.  If
  more than one structure has the same field name, the value of the field will
  be given by the last structure.
  
  If an input value is a string, then it will be interpreted as a structure
  with a single field of the corresponding name.  This is a useful feature
  when one wants to expand a structure with new field names, e.g.,
#v+
    s = struct { foo, bar };
    t = struct_combine (s, "baz");   % t = struct {foo, bar, baz};
#v-
\seealso{get_struct_field_names}
\done

\function{struct_field_exists}
\synopsis{Determine whether or not a structure contains a specified field}
\usage{Int_Type struct_field_exists (Struct_Type s, String_Type f)}
\description
 This function may be used to determine if a structure contains a field with
 a specfied name.  It returns 0 if the structure does not contain the field, 
 or non-zero if it does.
\seealso{get_struct_field_names}
\done