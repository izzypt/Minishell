# Minishell
This project is about creating a simple shell. We will learn a lot about processes and file descriptors.

## Current Fails

- Try Ctrl - C  after running a blocking command like cat without arguments.
- Try Ctrl - \  after running a blocking command like cat without arguments.
- Execute a simple command with arguments and , this time, use double quotes. Examples:
  - "ls -la"
  - "   /usr/bin/ls -la"
- Execute a simple command with arguments and , this time, using single quotes
## Checks
[X] Simao:cd is not working

[X] Simao: exit is no working

[] set exit status

[] check is valid command

[X] Simao: echo without arguments sens deadly signal

[] after control-c in blocking command -> 2 new lines

[x] quotes: leaks

[X] export env var

[X] unset

[] heredoc update fds

[x] echo $USER -> fill_env parse/var_expansion.c:77 -> memory issue

[]






## TODO :
- Make sure Makefile doesnt have wildcards.
- Handle "$?" , investigate what exit status is and which status we hould have in which situations.

## Key concepts

### Redirections
  - In Bash or shell scripting, redirections are used to manipulate input and output streams of commands and scripts.
  - They allow you to control where the input comes from and where the output goes. Bash provides several redirection operators to perform different types of redirections.

  - Here are the commonly used redirection operators:

    - 1 Standard Output (STDOUT) Redirection (`>`):
      - The `>` operator is used to redirect the standard output of a command to a file instead of displaying it on the terminal. For example:
       ```
       command > output.txt
       ```
       - This command runs `command` and writes its output to the file `output.txt`.
       - If the file doesn't exist, it will be created. If it exists, it will be overwritten.

    - 2 Append Output (STDOUT) Redirection (`>>`):
      - The `>>` operator is used to append the standard output of a command to the end of a file. For example:
       ```
       command >> output.txt
       ```
       - This command appends the output of `command` to the existing content of `output.txt` or creates a new file if it doesn't exist.

    - 3 Standard Error (STDERR) Redirection (`2>` or `2>>`):
      - By default, errors or diagnostic messages generated by a command are sent to the standard error stream (STDERR). You can redirect them to a file   using `2>` for overwriting or `2>>` for appending. For example:
       ```
       command 2> error.txt
       ```
       This command redirects the error output of `command` to the file `error.txt`.

    - 4 Input Redirection (`<`): The `<` operator is used to redirect the input of a command from a file instead of the keyboard. For example:
       ```
       command < input.txt
       ```
       This command takes the input for `command` from the file `input.txt`.

### Heredocs
   - Here Document (`<<`): The `<<` operator is used to provide input to a command or script from the script itself.
   - It allows you to include multiple lines of input within the script. For example:
       ```
       command << EOF
       line 1
       line 2
       EOF
       ```
       This command passes the lines between `<< EOF` and `EOF` as input to `command`.
### Pipes
  - Pipes (`|`): Pipes are not technically redirections, but they are closely related. Pipes allow you to take the output of one command and use it as the input for another command. For example:
       ```
       command1 | command2
       ```
       This command passes the output of `command1` as input to `command2`.

### Paths, environments and variables
- The PATH variable is an essential environment variable in Unix-like operating systems, including Linux.
- It plays a crucial role in locating executable files, commonly referred to as binaries or commands, when you issue a command in the terminal.
- The PATH variable is a list of directory paths separated by colons (':').
- When you type a command in the terminal, the system searches for the corresponding executable file in each directory listed in the PATH, in the order they appear.
- If the executable file is found in one of the directories, it is executed; otherwise, you'll receive a "command not found" error.
### Variable expansion
  - Variable expansions in the context of a Bash or shell refer to the process of substituting the values of variables within a command or string. When a variable is expanded, its value is replaced by the actual content it holds.

  - In Bash or shell scripting, variables are defined by assigning a value to them using the syntax variable_name=value. Variable expansion occurs when the variable is referenced, typically by prefixing the variable name with a $ sign. There are different ways to expand variables:

     - Simple Variable Expansion: This is the most common form of variable expansion. It is done by placing the variable name preceded by a $ sign. For example, if you have a variable name with the value "John," you can expand it using $name, which will be replaced with "John" in the command or string.

      - Brace Expansion: Brace expansion allows you to generate multiple strings based on a pattern. It is done by enclosing the variable name within curly braces {}. For example, if you have a variable number with the value "1 2 3," you can expand it using ${number}, which will be replaced with "1 2 3" in the command or string.

      - Command Substitution: Command substitution allows you to execute a command and substitute its output into a variable. It is done by enclosing the command within $(command) or backticks `command`. For example, if you have a variable files with the value $(ls), it will be expanded by executing the ls command and substituting its output.

      - Arithmetic Expansion: Arithmetic expansion allows you to perform mathematical operations within a variable. It is done by enclosing the mathematical expression within $((expression)). For example, if you have a variable num with the value 5, you can expand it using $((num + 2)), which will be replaced with 7 in the command or string.
  - Signals
  - Builtin functions

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

https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
