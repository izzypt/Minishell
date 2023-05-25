# Minishell
This project is about creating a simple shell. We will learn a lot about processes and file descriptors.

this is ...

# Tasks

Simao:

- I will write a description for each function on the ReadME

Emily :

- Start doing Makefile


# Allowed functions

Here's a brief description of each allowed function for the current project :

Libraries required :

- <stdio.h> 
- <stdlib.h> 
- <unistd.h>
- <signal.h> 
- <fcntl.h> 
- <sys/stat.h>
- <dirent.h>
- <string.h>
- <errno.h>
- <termios.h>
- <curses.h>

1. `readline`: Reads a line of input from the user, including line editing capabilities.

2. `rl_clear_history`: Clears the history list used by the `readline` function.

3. `rl_on_new_line`: Informs `readline` that the cursor has moved to a new line.

4. `rl_replace_line`: Replaces the current input line with a new line.

5. `rl_redisplay`: Updates the display to show the current input line.

6. `add_history`: Adds a line to the history list used by the `readline` function.

7. `printf`: Prints formatted output to the console.

8. `malloc`: Allocates a block of memory on the heap.

9. `free`: Releases a previously allocated block of memory.

10. `write`: Writes data to a file descriptor.

11. `access`: Checks the accessibility of a file.

12. `open`: Opens a file or creates it if it doesn't exist.

13. `read`: Reads data from a file descriptor.

14. `close`: Closes a file descriptor.

15. `fork`: Creates a new process by duplicating the existing process.

16. `wait`: Suspends execution until one of its child processes exits.

17. `waitpid`: Waits for a specific child process to exit.

18. `wait3`, `wait4`: Older versions of the `wait` functions with additional options.

19. `signal`: Sets a signal handler for a specific signal.

20. `sigaction`: Sets a signal handler using a more modern and flexible approach.

21. `sigemptyset`: Initializes an empty signal set.

22. `sigaddset`: Adds a signal to a signal set.

23. `kill`: Sends a signal to a process or a group of processes.

24. `exit`: Terminates the current process and returns an exit status.

25. `getcwd`: Gets the current working directory.

26. `chdir`: Changes the current working directory.

27. `stat`, `lstat`, `fstat`: Retrieves information about a file or file descriptor.

28. `unlink`: Deletes a file.

29. `execve`: Executes a program.

30. `dup`, `dup2`: Duplicates a file descriptor.

31. `pipe`: Creates a pipe for interprocess communication.

32. `opendir`, `readdir`, `closedir`: Functions for working with directories.

33. `strerror`: Retrieves the string description of an error code.

34. `perror`: Prints a descriptive error message to the console.

35. `isatty`: Checks if a file descriptor refers to a terminal.

36. `ttyname`: Returns the name of the terminal associated with a file descriptor.

37. `ttyslot`: Returns the slot number of the current terminal.

38. `ioctl`: Performs I/O control operations on a file descriptor.

39. `getenv`: Retrieves the value of an environment variable.

40. `tcsetattr`, `tcgetattr`: Functions for setting and getting terminal attributes.

41. `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`: Functions for working with terminal capabilities in a termcap or terminfo database.


