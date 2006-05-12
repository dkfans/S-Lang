\function{getegid}
\synopsis{Get the effective group id of the current process}
\usage{Int_Type getegid ()}
\description
  The \ifun{getegid} function returns the effective group ID of the
  current process.
\notes
  This function is not supported by all systems.
\seealso{getgid, geteuid, setgid}
\done

\function{geteuid}
\synopsis{Get the effective user-id of the current process}
\usage{Int_Type geteuid ()}
\description
  The \ifun{geteuid} function returns the effective user-id of the
  current process.
\notes
  This function is not supported by all systems.
\seealso{getuid, setuid, setgid}
\done

\function{getgid}
\synopsis{Get the group id of the current process}
\usage{Integer_Type getgid ()}
\description
  The \ifun{getgid} function returns the real group id of the current
  process.
\notes
  This function is not supported by all systems.
\seealso{getpid, getppid}
\done

\function{getpid}
\synopsis{Get the current process id}
\usage{Integer_Type getpid ()}
\description
  The \ifun{getpid} function returns the current process identification
  number.
\seealso{getppid, getgid}
\done

\function{getppid}
\synopsis{Get the parent process id}
\usage{Integer_Type getppid ()}
\description
  The \ifun{getpid} function returns the process identification
  number of the parent process.
\notes
  This function is not supported by all systems.
\seealso{getpid, getgid}
\done

\function{getuid}
\synopsis{Get the user-id of the current process}
\usage{Int_Type getuid ()}
\description
  The \ifun{getuid} function returns the user-id of the current
  process.
\notes
  This function is not supported by all systems.
\seealso{getuid, getegid}
\done

\function{kill}
\synopsis{Send a signal to a process}
\usage{Integer_Type kill (Integer_Type pid, Integer_Type sig)}
\description
  This function may be used to send a signal given by the integer \exmp{sig}
  to the process specified by \exmp{pid}.  The function returns zero upon
  success or \exmp{-1} upon failure setting \ivar{errno} accordingly.
\example
  The \ifun{kill} function may be used to determine whether or not
  a specific process exists:
#v+
    define process_exists (pid)
    {
       if (-1 == kill (pid, 0))
         return 0;     % Process does not exist
       return 1;
    }
#v-
\notes
  This function is not supported by all systems.
\seealso{getpid}
\done

\function{mkfifo}
\synopsis{Create a named pipe}
\usage{Int_Type mkfifo (String_Type name, Int_Type mode)}
\description
  The \ifun{mkfifo} attempts to create a named pipe with the specified
  name and mode (modified by the process's umask).  The function
  returns 0 upon success, or -1 and sets \ivar{errno} upon failure.
\notes
  Not all systems support the \ifun{mkfifo} function and even on
  systems that do implement the \ifun{mkfifo} system call, the
  underlying file system may not support the concept of a named pipe,
  e.g, an NFS filesystem.
\seealso{stat_file}
\done

\function{setgid}
\synopsis{Set the group-id of the current process}
\usage{Int_Type setgid (Int_Type gid)}
\description
  The \ifun{setgid} function sets the effective group-id of the current
  process.  It returns zero upon success, or -1 upon error and sets
  \ivar{errno} appropriately.
\notes
  This function is not supported by all systems.
\seealso{getgid, setuid}
\done

\function{setpgid}
\synopsis{Set the process group-id}
\usage{Int_Type setpgid (Int_Type pid, Int_Type gid)}
\description
  The \ifun{setpgid} function sets the group-id \exmp{gid} of the
  process whose process-id is \exmp{pid}.  If \exmp{pid} is \0, then the
  current process-id will be used.  If \exmp{pgid} is \0, then the pid
  of the affected process will be used.
  
  If successful 0 will be returned, otherwise the function will
  return \-1 and set \ivar{errno} accordingly.
\notes
  This function is not supported by all systems.
\seealso{setgid, setuid}
\done

\function{setuid}
\synopsis{Set the user-id of the current process}
\usage{Int_Type setuid (Int_Type id)}
\description
  The \ifun{setuid} function sets the effective user-id of the current
  process.  It returns zero upon success, or \-1 upon error and sets
  \ivar{errno} appropriately.
\notes
  This function is not supported by all systems.
\seealso{setgid, setpgid, getuid, geteuid}
\done

\function{sleep}
\synopsis{Pause for a specified number of seconds}
\usage{sleep (Double_Type n)}
\description
  The \ifun{sleep} function delays the current process for the
  specified number of seconds.  If it is interrupted by a signal, it
  will return prematurely.
\notes
  Not all system support sleeping for a fractional part of a second.
\done

\function{system}
\synopsis{Execute a shell command}
\usage{Integer_Type system (String_Type cmd)}
\description
  The \ifun{system} function may be used to execute the string
  expression \exmp{cmd} in an inferior shell.  This function is an
  interface to the C \ifun{system} function which returns an
  implementation-defined result.   On Linux, it returns 127 if the
  inferior shell could not be invoked, -1 if there was some other
  error, otherwise it returns the return code for \exmp{cmd}.
\example
#v+
    define dir ()
    {
       () = system ("DIR");
    }
#v-
  displays a directory listing of the current directory under MSDOS or
  VMS.
\seealso{popen, listdir}
\done

\function{umask}
\synopsis{Set the file creation mask}
\usage{Int_Type umask (Int_Type m)}
\description
  The \ifun{umask} function sets the file creation mask to the value of
  \exmp{m} and returns the previous mask.
\seealso{stat_file}
\done

\function{uname}
\synopsis{Get the system name}
\usage{Struct_Type uname ()}
\description
  The \ifun{uname} function returns a structure containing information
  about the operating system.  The structure contains the following
  fields:
#v+
       sysname  (Name of the operating system)
       nodename (Name of the node within the network)
       release  (Release level of the OS)
       version  (Current version of the release)
       machine  (Name of the hardware)
#v-
\notes
  Not all systems support this function.
\seealso{getenv}
\done

