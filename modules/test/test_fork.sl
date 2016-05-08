% -*- mode: slang; mode: fold -*-

() = evalfile ("./test.sl");

require ("fork");

private define test_fork ()
{
   variable pid = fork ();

   if (pid == 0)
     {
	% child
	_exit(123);
     }

   variable w = waitpid (pid, 0);
   if (w.exited)
     {
	if (w.exit_status != 123)
	  failed ("child exited with unexpected status of %d", w.exit_status);
     }
}

private define test_pipe ()
{
   variable fdr, fdw, buf, n;
   (fdr, fdw) = pipe ();

   () = write (fdw, "hello");
   n = read (fdr, &buf, 10);
   if ((buf != "hello") || (n != 5))
     {
	failed ("pipe failed");
     }
}

define slsh_main ()
{
   testing_module ("fork");
   test_fork ();
   test_pipe ();
   %test_exec ();
   end_test ();
}