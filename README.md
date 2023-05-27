# Minishell
This project is about creating a simple shell. We will learn a lot about processes and file descriptors.

### Key concepts

- Redirections
- Paths, environments and variables
- Heredocs
- Pipes
- Variable expansion
  - Variable expansions in the context of a Bash or shell refer to the process of substituting the values of variables within a command or string. When a variable is expanded, its value is replaced by the actual content it holds.

  - In Bash or shell scripting, variables are defined by assigning a value to them using the syntax variable_name=value. Variable expansion occurs when the variable is referenced, typically by prefixing the variable name with a $ sign. There are different ways to expand variables:

     - Simple Variable Expansion: This is the most common form of variable expansion. It is done by placing the variable name preceded by a $ sign. For example, if you have a variable name with the value "John," you can expand it using $name, which will be replaced with "John" in the command or string.

      - Brace Expansion: Brace expansion allows you to generate multiple strings based on a pattern. It is done by enclosing the variable name within curly braces {}. For example, if you have a variable number with the value "1 2 3," you can expand it using ${number}, which will be replaced with "1 2 3" in the command or string.

      - Command Substitution: Command substitution allows you to execute a command and substitute its output into a variable. It is done by enclosing the command within $(command) or backticks `command`. For example, if you have a variable files with the value $(ls), it will be expanded by executing the ls command and substituting its output.

      - Arithmetic Expansion: Arithmetic expansion allows you to perform mathematical operations within a variable. It is done by enclosing the mathematical expression within $((expression)). For example, if you have a variable num with the value 5, you can expand it using $((num + 2)), which will be replaced with 7 in the command or string.
  - Signals
  - Builtin functions

### Tasks

- Prompt implementation
- HashTable functions implementation
- Tokenizer implementation
- Variables expansion implementation
- Builtins implementation
- Parse and execute sistem design
- Signals implementation
- Parsing implementation
- Execute implementation
- Norme
- Bugs hunting

I found this mind map from another rep, it might be helpfull :

![image](https://github.com/izzypt/Minishell/assets/73948790/d9f54c44-2d33-4081-95c8-f9e8d604f381)

# Allowed functions

Here's a brief description of each allowed function for the current project :

### Libraries required :

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


https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
