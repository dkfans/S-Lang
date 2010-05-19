\function{all}
\synopsis{Tests if all elements of an array are non-zero}
\usage{Char_Type all (Array_Type a [,Int_Type dim])}
\description
  The \ifun{all} function examines the elements of a numeric array and
  returns 1 if all elements are non-zero, otherwise it returns 0. If a
  second argument is given, then it specifies the dimension of the
  array over which the function is to be applied.  In this case, the
  result will be an array with the same shape as the input array minus
  the specified dimension.
\example
  Consider the 2-d array
#v+
      1       2       3       4        5
      6       7       8       9       10
#v-
  generated by
#v+
      a = _reshape ([1:10], [2, 5]);
#v-
  Then \exmp{all(a)} will return 1, and \exmp{all(a>3, 0)} will return
  a 1-d array
#v+
      [0, 0, 0, 1, 1]
#v-
  Similarly, \exmp{all(a>3, 1)} will return the 1-d array
#v+
      [0,1]
#v-
\seealso{where, any}
\done

\function{any}
\synopsis{Test if any element of an array is non-zero}
\usage{Char_Type any (Array_Type a [,Int_Type dim])}
\description
  The \ifun{any} function examines the elements of a numeric array and
  returns 1 if any element is both non-zero and not a NaN, otherwise
  it returns 0.  If a second argument is given, then it specifies
  the dimension of the array to be tested.
\example
  Consider the 2-d array
#v+
      1       2       3       4        5
      6       7       8       9       10
#v-
  generated by
#v+
      a = _reshape ([1:10], [2, 5]);
#v-
  Then \exmp{any(a==3)} will return 1, and \exmp{any(a==3, 0)}
  will return a 1-d array with elements:
#v+
      0        0       1       0       0
#v-
\seealso{where, all}
\done

\function{array_info}
\synopsis{Returns information about an array}
\usage{(Array_Type, Integer_Type, DataType_Type) array_info (Array_Type a)}
\description
  The \ifun{array_info} function returns information about the array \exmp{a}.
  It returns three values: an 1-d integer array specifying the
  size of each dimension of \exmp{a}, the number of dimensions of
  \exmp{a}, and the data type of \exmp{a}.
\example
  The \ifun{array_info} function may be used to find the number of rows
  of an array:
#v+
    define num_rows (a)
    {
       variable dims, num_dims, data_type;

       (dims, num_dims, data_type) = array_info (a);
       return dims [0];
    }
#v-
\seealso{typeof, array_shape, length, reshape, _reshape}
\done

\function{array_map}
\synopsis{Apply a function to each element of an array}
\usage{Array_Type array_map (type, func, arg0, ...)}
#v+
    DataType_Type type;
    Ref_Type func;
#v-
\description
  The \ifun{array_map} function may be used to apply a function to each
  element of an array and returns the resulting values as an array of
  the specified type.  The \exmp{type} parameter indicates what kind of
  array should be returned and generally corresponds to the return
  type of the function.  The \exmp{arg0} parameter should be an array
  and is used to determine the dimensions of the resulting array.  If
  any subsequent arguments correspond to an array of the same size,
  then those array elements will be passed in parallel with the first
  arrays arguments.
\example
  The first example illustrates how to apply the \ifun{strlen} function
  to an array of strings:
#v+
     S = ["", "Train", "Subway", "Car"];
     L = array_map (Integer_Type, &strlen, S);
#v-
  This is equivalent to:
#v+
     S = ["", "Train", "Subway", "Car"];
     L = Integer_Type [length (S)];
     for (i = 0; i < length (S); i++) L[i] = strlen (S[i]);
#v-
  
  Now consider an example involving the \ifun{strcat} function:
#v+
     files = ["slang", "slstring", "slarray"];

     exts = ".c";
     cfiles = array_map (String_Type, &strcat, files, exts);
     % ==> cfiles = ["slang.c", "slstring.c", "slarray.c"];

     exts =  [".a",".b",".c"];
     xfiles = array_map (String_Type, &strcat, files, exts);
     % ==> xfiles = ["slang.a", "slstring.b", "slarray.c"];
#v-
\notes
  Many mathematical functions already work transparently on arrays.
  For example, the following two statements produce identical results:
#v+
     B = sin (A);
     B = array_map (Double_Type, &sin, A);
#v-
\seealso{array_info, strlen, strcat, sin}
\done

\function{array_reverse}
\synopsis{Reverse the elements of an array}
\usage{array_reverse (Array_Type a [,Int_Type i0, Int_Type i1] [,Int_Type dim])}
\description
  In its simplest form, the \ifun{array_reverse} function reverses the
  elements of an array.  If passed 2 or 4 arguments,
  \ifun{array_reverse} reverses the elements of the specified
  dimension of a multi-dimensional array.  If passed 3 or 4 arguments,
  the parameters \exmp{i0} and \exmp{i1} specify a range of elements
  to reverse.
\example
  If \exmp{a} is a one dimensional array, then
#v+
    array_reverse (a, i, j);
    a[[i:j]] = a[[j:i:-1]];
#v-
  are equivalent to one another.  However, the form using
  \ifun{array_reverse} is about 10 times faster than the version that
  uses explicit array indexing.
\seealso{array_swap, transpose}
\done

\function{array_shape}
\synopsis{Get the shape or dimensions of an array}
\usage{dims = array_shape (Array_Type a)}
\description
   This function returns an array representing the dimensionality or
   shape of a specified array.  The \ifun{array_info} function also
   returns this information but for many purposes the
   \ifun{array_shape} function is more convenient.
\seealso{array_info, reshape}
\done

\function{array_sort}
\synopsis{Sort an array or opaque object}
\usage{Array_Type array_sort (obj [, &func [, n]])}
\description
  The \ifun{array_sort} function may be used to sort an object and
  returns an integer index array that represents the result of the
  sort as a permutation.  
  
  If a single parameter is passed, that parameter must be an array,
  which will be sorted into ascending order using a built-in type-specific
  comparison function.
  
  If two parameters are passed (\exmp{obj} and \exmp{func}), then the
  first parameter must be the array to be sorted, and the second is a
  reference to the comparison function.  In this case, the comparison
  function represented by \exmp{func} must take two arguments
  representing two array elements to be compared, and must return an
  integer that represents the result of the comparison.  The return
  value must be less than zero if the first parameter is
  less than the second, zero if they are equal, and a value greater
  than zero if the first is greater than the second.

  If three parameters are passed, then the first argument will be
  regarded as an opaque object by the sorting algorithm.  For this
  reason, the number of elements represented by the object must also
  be passed to \ifun{array_sort} function as the third function
  argument.  The second function argument must be a reference to
  comparison function.  In this case, the comparison function will be
  passed three values: the opaque object, the (0-based) index of the
  first element to be compared, and the (0-based) index of the second
  element.  The return value must be less than zero if the value of
  the element at the first index considered to be less than the value
  of the element at the second index, zero if the values are equal,
  and a value greater than zero if the first value is greater than the
  second.

  \ifun{array_sort} sorts the array \exmp{a} into ascending order and
  returns an integer array that represents the result of the sort. If
  the optional second parameter \exmp{f} is present, the function
  specified by \exmp{f} will be used to compare elements of \exmp{a};
  otherwise, a built-in sorting function will be used.  

  The integer array returned by this function is simply an index array
  that indicates the order of the sorted object.  The input object
  \exmp{obj} is not changed.

\qualifiers
  By default, elements are sorted in ascending order.  The \exmp{dir}
  qualifier may be used to specify the sort direction.  Specifically
  if \exmp{dir>=0}, the sort will be an ascending one, otherwise it
  will be descending.

\example
  An array of strings may be sorted using the \ifun{strcmp} function
  since it fits the specification for the sorting function described
  above:
#v+
     A = ["gamma", "alpha", "beta"];
     I = array_sort (A, &strcmp);
#v-
  Alternatively, one may use
#v+
     variable I = array_sort (A);     
#v-
  to use the built-in comparison function.

  After the \ifun{array_sort} has executed, the variable \exmp{I} will
  have the values \exmp{[2, 0, 1]}.  This array can be used to
  re-shuffle the elements of \exmp{A} into the sorted order via the
  array index expression \exmp{A = A[I]}.  This operation may also be
  written:
#v+
     A = A[array_sort(A)];
#v-
\example
  A homogeneous list may be sorted by using the opaque form of the
  \ifun{array_sort} function:
#v+
    private define cmp_function (s, i, j)
    { 
       if (s[i] > s[j]) return 1;
       if (s[i] < s[j]) return -1;
       return 0;
    }
    
    list = {};
    % fill list ....
    % now sort it
    i = array_sort (list, &cmp_function, length(list));
    
    % Create a new sorted list
    list = list[i];
#v-
  Alternatively one may first convert it to an array and use the
  built-in comparison function:
#v+
    a = list_to_array (list);
    i = array_sort(a);

    % Rearrange the elements
    list[*] = a[i];
#v-
  to get the effect of an "in-place" sort.
\notes
  The underlying sorting algorithm is based upon merge-sort.  This is a
  stable sorting algorithm that preserves the order equal elements.
\seealso{strcmp, list_to_array}
\done

\function{array_swap}
\synopsis{Swap elements of an array}
\usage{array_swap (Array_Type a, Int_Type i, Int_Type j)}
\description
  The \ifun{array_swap} function swaps the specified elements of an
  array.  It is equivalent to
#v+
    (a[i], a[j]) = (a[j], a[i]);
#v-
  except that it executes several times faster than the above construct.
\seealso{array_reverse, transpose}
\done

\function{cumsum}
\synopsis{Compute the cumulative sum of an array}
\usage{result = cumsum (Array_Type a [, Int_Type dim])}
\description
  The \ifun{cumsum} function performs a cumulative sum over the
  elements of a numeric array and returns the result.  If a second
  argument is given, then it specifies the dimension of the array to
  be summed over.  For example, the cumulative sum of
  \exmp{[1,2,3,4]}, is the array \exmp{[1,1+2,1+2+3,1+2+3+4]}, i.e.,
  \exmp{[1,3,6,10]}.
\seealso{sum, sumsq}
\done

\function{init_char_array}
\synopsis{Initialize an array of characters}
\usage{init_char_array (Array_Type a, String_Type s)}
\description
  The \ifun{init_char_array} function may be used to initialize a
  character array \exmp{a} by setting the elements of the array
  \exmp{a} to the corresponding characters of the string \exmp{s}.
\example
  The statements
#v+
     variable a = Char_Type [10];
     init_char_array (a, "HelloWorld");
#v-
   creates an character array and initializes its elements to the
   characters in the string \exmp{"HelloWorld"}.
\notes
   The character array must be large enough to hold all the characters
   of the initialization string.
\seealso{bstring_to_array, strlen, strcat}
\done

\function{_isnull}
\synopsis{Check an array for NULL elements}
\usage{Char_Type[] = _isnull (a[])}
\description
  This function may be used to test for the presence of NULL elements
  of an array.   Specifically, it returns a \dtype{Char_Type} array of
  with the same number of elements and dimensionality of the input
  array.  If an element of the input array is \NULL, then the
  corresponding element of the output array will be set to \1,
  otherwise it will be set to \0.
\example
  Set all \NULL elements of a string array \exmp{A} to the empty
  string \exmp{""}:
#v+
     A[where(_isnull(A))] = "";
#v-
\notes
  It is important to understand the difference between \exmp{A==NULL}
  and \exmp{_isnull(A)}.  The latter tests all elements of \exmp{A}
  against \NULL, whereas the former only tests \exmp{A} itself.
\seealso{where, array_map}
\done

\function{length}
\synopsis{Get the length of an object}
\usage{Integer_Type length (obj)}
\description
  The \ifun{length} function may be used to get information about the
  length of an object.  For simple scalar data-types, it returns 1.
  For arrays, it returns the total number of elements of the array.
\notes
  If \exmp{obj} is a string, \ifun{length} returns \1 because a
  \dtype{String_Type} object is considered to be a scalar.  To get the
  number of characters in a string, use the \ifun{strlen} function.
\seealso{array_info, array_shape, typeof, strlen}
\done

\function{max}
\synopsis{Get the maximum value of an array}
\usage{result = max (Array_Type a [,Int_Type dim])}
\description
  The \ifun{max} function examines the elements of a numeric array and
  returns the value of the largest element.  If a second argument is
  given, then it specifies the dimension of the array to be searched.
  In this case, an array of dimension one less than that of the input array
  will be returned with the corresponding elements in the specified
  dimension replaced by the maximum value in that dimension.
\example
  Consider the 2-d array
#v+
      1       2       3       4        5
      6       7       8       9       10
#v-
  generated by
#v+
      a = _reshape ([1:10], [2, 5]);
#v-
  Then \exmp{max(a)} will return \exmp{10}, and \exmp{max(a,0)} will return
  a 1-d array with elements
#v+
      6       7       8       9       10
#v-
\notes
  This function ignores NaNs in the input array.
\seealso{min, maxabs, sum, reshape}
\done

\function{maxabs}
\synopsis{Get the maximum absolute value of an array}
\usage{result = maxabs (Array_Type a [,Int_Type dim])}
\description
  The \ifun{maxabs} function behaves like the \ifun{max} function
  except that it returns the maximum absolute value of the array. That
  is, \exmp{maxabs(x)} is equivalent to \exmp{max(abs(x)}. See the
  documentation for the \ifun{max} function for more information.
\seealso{min, max, minabs}
\done

\function{min}
\synopsis{Get the minimum value of an array}
\usage{result = min (Array_Type a [,Int_Type dim])}
\description
  The \ifun{min} function examines the elements of a numeric array and
  returns the value of the smallest element.  If a second argument is
  given, then it specifies the dimension of the array to be searched.
  In this case, an array of dimension one less than that of the input array
  will be returned with the corresponding elements in the specified
  dimension replaced by the minimum value in that dimension.
\example
  Consider the 2-d array
#v+
      1       2       3       4       5
      6       7       8       9       10
#v-
  generated by
#v+
      a = _reshape ([1:10], [2, 5]);
#v-
  Then \exmp{min(a)} will return \exmp{1}, and \exmp{min(a,0)} will return
  a 1-d array with elements
#v+
      1        2       3       4       5
#v-
\notes
  This function ignores NaNs in the input array.
\seealso{max, sum, reshape}
\done

\function{minabs}
\synopsis{Get the minimum absolute value of an array}
\usage{result = minabs (Array_Type a [,Int_Type dim])}
\description
  The \ifun{minabs} function behaves like the \ifun{min} function
  except that it returns the minimum absolute value of the array. That
  is, \exmp{minabs(x)} is equivalent to \exmp{min(abs(x)}. See the
  documentation for the \ifun{min} function for more information.
\seealso{min, max, maxabs}
\done

\function{_reshape}
\synopsis{Copy an array to a new shape}
\usage{Array_Type _reshape (Array_Type A, Array_Type I)}
\description
  The \ifun{_reshape} function creates a copy of an array \exmp{A},
  reshapes it to the form specified by \exmp{I} and returns the result.
  The elements of \exmp{I} specify the new dimensions of the copy of
  \exmp{A} and must be consistent with the number of elements \exmp{A}.
\example
  If \exmp{A} is a \exmp{100} element 1-d array, a new 2-d array of
  size \exmp{20} by \exmp{5} may be created from the elements of \exmp{A}
  by
#v+
      B = _reshape (A, [20, 5]);
#v-
\notes
  The \ifun{reshape} function performs a similar function to
  \ifun{_reshape}.  In fact, the \ifun{_reshape} function could have been
  implemented via:
#v+
     define _reshape (a, i)
     {
        a = @a;     % Make a new copy
        reshape (a, i);
        return a;
     }
#v-
\seealso{reshape, array_shape, array_info}
\done

\function{reshape}
\synopsis{Reshape an array}
\usage{reshape (Array_Type A, Array_Type I)}
\description
  The \ifun{reshape} function changes the shape of \exmp{A} to have the
  shape specified by the 1-d integer array \exmp{I}.  The elements of \exmp{I}
  specify the new dimensions of \exmp{A} and must be consistent with
  the number of elements \exmp{A}.
\example
  If \exmp{A} is a \exmp{100} element 1-d array, it can be changed to a
  2-d \exmp{20} by \exmp{5} array via
#v+
      reshape (A, [20, 5]);
#v-
  However, \exmp{reshape(A, [11,5])} will result in an error because
  the \exmp{[11,5]} array specifies \exmp{55} elements.
\notes
  Since \ifun{reshape} modifies the shape of an array, and arrays are
  treated as references, then all references to the array will
  reference the new shape.  If this effect is unwanted, then use the 
  \ifun{_reshape} function instead.
\seealso{_reshape, array_info, array_shape}
\done

\function{sum}
\synopsis{Sum over the elements of an array}
\usage{result = sum (Array_Type a [, Int_Type dim])}
\description
  The \ifun{sum} function sums over the elements of a numeric array and
  returns its result.  If a second argument is given, then it
  specifies the dimension of the array to be summed over.  In this
  case, an array of dimension one less than that of the input array
  will be returned.

  If the input array is an integer type, then the resulting value will
  be a \dtype{Double_Type}.  If the input array is a \dtype{Float_Type},
  then the result will be a \dtype{Float_Type}.
\example
  The mean of an array \exmp{a} of numbers is
#v+
    sum(a)/length(a)
#v-
\seealso{cumsum, sumsq, transpose, reshape}
\done

\function{sumsq}
\synopsis{Sum over the squares of the elements of an array}
\usage{result = sumsq (Array_Type a [, Int_Type dim])}
\description
  The \ifun{sumsq} function sums over the squares of the elements of a
  numeric array and returns its result.  If a second argument is
  given, then it specifies the dimension of the array to be summed
  over.  In this case, an array of dimension one less than that of the
  input array will be returned.

  If the input array is an integer type, then the resulting value will
  be a \dtype{Double_Type}.  If the input array is a \dtype{Float_Type},
  then the result will be a \dtype{Float_Type}.
  
  For complex arrays, the sum will be over the squares of the moduli of
  the complex elements.
\seealso{cumsum, sumsq, hypot, transpose, reshape}
\done

\function{transpose}
\synopsis{Transpose an array}
\usage{Array_Type transpose (Array_Type a)}
\description
  The \ifun{transpose} function returns the transpose of a specified
  array.  By definition, the transpose of an array, say one with
  elements \exmp{a[i,j,...k]} is an array whose elements are
  \exmp{a[k,...,j,i]}.
\seealso{_reshape, reshape, sum, array_info, array_shape}
\done

\function{where}
\usage{Array_Type where (Array_Type a [, Ref_Type jp])}
\description
  The \ifun{where} function examines a numeric array \exmp{a} and
  returns an integer array giving the indices of \exmp{a}
  where the corresponding element of \exmp{a} is non-zero.  The
  function accepts an optional \dtype{Ref_Type} argument that will be
  set to complement set of indices, that is, the indices where
  \exmp{a} is zero.  In fact
#v+
     i = where (a);
     j = where (not a);
#v-
  and
#v+
     i = where (a, &j);
#v-
  are equivalent, but the latter form is preferred since it executes
  about twice as fast as the former.

  Although this function may appear to be simple or even trivial, it
  is arguably one of the most important and powerful functions for
  manipulating arrays.
\example
  Consider the following:
#v+
    variable X = [0.0:10.0:0.01];
    variable A = sin (X);
    variable I = where (A < 0.0);
    A[I] = cos (X) [I];
#v-
  Here the variable \exmp{X} has been assigned an array of doubles
  whose elements range from \exmp{0.0} through \exmp{10.0} in
  increments of \exmp{0.01}.  The second statement assigns \exmp{A} to
  an array whose elements are the \ifun{sin} of the elements of \exmp{X}.
  The third statement uses the \ifun{where} function to get the indices of
  the elements of \exmp{A} that are less than 0.  Finally, the
  last statement replaces those elements of \exmp{A} by the cosine of the
  corresponding elements of \exmp{X}.
\notes
  Support for the optional argument was added to version 2.1.0.
\seealso{wherefirst, wherelast, wherenot, array_info, array_shape, _isnull}
\done


\function{wherenot}
\synopsis{Get indices where a numeric array is 0}
\usage{Array_Type wherenot (Array_Type)}
\description
  This function is equivalent to \exmp{where(not a)}.  See the
  documentation for \ifun{where} for more information.
\seealso{where, wherefirst, wherelast}
\done

\function{wherefirst}
\synopsis{Get the index of the first non-zero array element}
\usage{Int_Type wherefirst (Array_Type a [,start_index])}
\description
  The \ifun{wherefirst} function returns the index of the first
  non-zero element of a specified array.  If the optional parameter
  \exmp{start_index} is given, the search will take place starting
  from that index.  If a non-zero element is not found, the function
  will return \NULL.
\notes
  The single parameter version of this function is equivalent to
#v+
     define wherefirst (a)
     {
        variable i = where (a);
        if (length(i))
          return i[0];
        else
          return NULL;
     }
#v-
\seealso{where, wherelast}
\done

\function{wherelast}
\synopsis{Get the index of the last non-zero array element}
\usage{Int_Type wherelast (Array_Type a [,start_index])}
\description
  The \ifun{wherelast} function returns the index of the last
  non-zero element of a specified array.  If the optional parameter
  \exmp{start_index} is given, the backward search will take place starting
  from that index.  If a non-zero element is not found, the function
  will return \NULL.
\notes
  The single parameter version of this function is equivalent to
#v+
     define wherefirst (a)
     {
        variable i = where (a);
        if (length(i))
          return i[-1];
        else
          return NULL;
     }
#v-
\seealso{where, wherefirst}
\done

