\function{list_append}
\synopsis{Append an object to a list}
\usage{list_append (List_Type object, Int_Type nth)}
\description
  The \ifun{list_append} function is like \ifun{list_insert} except
  this function inserts the object into the list after the \exmp{nth}
  item.  See the documentation on \ifun{list_insert} for more details.
\seealso{list_insert, list_delete, list_pop, list_new, list_reverse}
\done

\function{list_delete}
\synopsis{Remove an item from a list}
\usage{list_delete (List_Type list, Int_Type nth)}
\description
  This function removes the \exmp{nth} item in the specified list.
  The first item in the list corresponds to a value of \exmp{nth}
  equal to zero.  If \exmp{nth} is negative, then the indexing is with
  respect to the end of the list with the last item corresponding to
  \exmp{nth} equal to -1.
\seealso{list_insert, list_append, list_pop, list_new, list_reverse}
\done

\function{list_insert}
\synopsis{Insert an item into a list}
\usage{list_insert (List_Type list, object, Int_Type nth)}
\description
  This function may be used to insert an object before the \exmp{nth}
  position in a list.  The first item in the list corresponds to a
  value of \exmp{nth} equal to zero.  If \exmp{nth} is negative, then
  the indexing is with respect to the end of the list with the last
  item given by a value of \exmp{nth} equal to -1.
\notes
  It is important to note that
#v+
    list_insert (list, object, 0);
#v-
  is not the same as
#v+
    list = {object, list}
#v-
  since the latter creates a new list with two items, \exmp{object}
  and the old list.
\seealso{list_append, list_pop, list_delete, list_new, list_reverse}
\done

\function{list_new}
\synopsis{Create a new list}
\usage{List_Type list_new ()}
\description
  This function creates a new empty \dtype{List_Type} object.  Such a
  list may also be created using the syntax
#v+
     list = {};
#v-
\seealso{list_delete, list_insert, list_append, list_reverse, list_pop}
\done

\function{list_pop}
\synopsis{Extract an item from a list}
\usage{object = list_pop (List_Type list [, Int_Type nth])}
\description
  The \ifun{list_pop} function returns a object from a list deleting
  the item from the list in the process.  If the second argument is
  present, then it may be used to specify the position in the list
  where the item is to be obtained.  If called with a single argument,
  the first item in the list will be used.
\seealso{list_delete, list_insert, list_append, list_reverse, list_new}
\done

\function{list_reverse}
\synopsis{Reverse a list}
\usage{list_reverse (List_Type list)}
\description
  This function may be used to reverse the items in list.
\notes
  This function does not create a new list.  The list passed to the
  function will be reversed upon return from the function.  If it is
  desired to create a separate reversed list, then a separate copy
  should be made, e.g.,
#v+
     rev_list = @list;
     list_reverse (rev_list);
#v-
\seealso{list_new, list_insert, list_append, list_delete, list_pop}
\done

