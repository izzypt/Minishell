# Minishell
This project is about creating a simple shell. We will learn a lot about processes and file descriptors.

Articles that say pipes block if there is nothing to read:

https://www.idc-online.com/technical_references/pdfs/information_technology/How_Linux_pipes_work_under_the_hood.pdf

http://brandonwamboldt.ca/how-linux-pipes-work-under-the-hood-1518/

# TODO

- [] cat | cat | ls
- [X] Ctrl-C
- [X] Ctrl + \
- [] Ctrl+\ in minishell lvl 2 is quitting
- [] Ctrl+C in minishell lvl 2 is not printing correctly
- [X] export 1hello (number in first place mot allowd)
- [X] export A =hello (cannot have space)
- [X] export: new elements not sorted in list
- [] several Heredocs
- [X] export several objects
- [] unset several objects
- [] decrease exit nr with 255 (limit long max int)
- [] SEGFAULTS:
	- [] Redirections
	- [X] 'cd'
	- [X] cd '../../../../../.../../../../..'
	- [X] 'export n' -> 'export n'
	- [X] 'export n' -> 'export n =something'
	- [X] './'
	- [X] unset HOME
	- [] '< Makefile < minishell.c cat > out > out2'
- [X] env something | grep HOME
- [] cd: change OLDPWD and PWD
- [X] CTRL+\ -> should not clear line
- [X] 'env something' should give an error
- [X] exit with argument, that is not numeric should give error
- [X] exit with any argument prints exit
- [X] CTRL-D should print exit in terminal
- [X] cat << EEOF segfault Ctrl-D
- [X] remove rl_clear_visible_line(). Find another way to clean the line.
- [] command chain:
	- [X] cat < input > out
	- [] redirections (>, >>, <, <<) as first token
	- [X] cat < input | grep test
	- [X] cat < file1 < file2 < file3 -> outputs only the contents of file3
	- [X] ls > file1 > file2 > file3 -> recreates every file and only outputs to last file (file3)
	- [x] ls >> file1 >> file2 >> file3 -> does not overwrite file1 and file2, but only appends ls to file3
- [X] echo < out "something" -> change token order
- [X] echo -nnnn3n
- [X] print options for echo
- [X] remove space when echo -n
- [X] echo $"PWD"
- [X] set exit status in cd (permission)
- [X] check permission for file before executing


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
       -echo "$USER" | grep $USER If the file doesn't exist, it will be created. If it exists, it will be overwritten.

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


### GNU Readline

1. `readline`: Reads a line of input from the user, including line editing capabilities.

2. `rl_clear_history`: Clears the history list used by the `readline` function.

3. `rl_on_new_line`: Informs `readline` that the cursor has moved to a new line.

4. `rl_replace_line`: Replaces the current input line with a new line.

5. `rl_redisplay`: Updates the display to show the current input line.

6. `add_history`: Adds a line to the history list used by the `readline` function.

### File Related Functions

10. `write`: Writes data to a file descriptor.

11. `access`: Checks the accessibility of a file.

12. `open`: Opens a file or creates it if it doesn't exist.

13. `read`: Reads data from a file descriptor.

14. `close`: Closes a file descriptor.

15. `stat`, `lstat`, `fstat`: Retrieves information about a file or file descriptor.

16. `unlink`: Deletes a file.

### Processes Related Functions

17. `wait`: Suspends execution until one of its child processes exits.

18. `waitpid`: Waits for a specific child process to exit.

19. `wait3`, `wait4`: Older versions of the `wait` functions with additional options.

20. `fork`: Creates a new process by duplicating the existing process.

### Signal Related Functions

21. `signal`: Sets a signal handler for a specific signal.

22. `sigaction`: Sets a signal handler using a more modern and flexible approach.

23. `sigemptyset`: Initializes an empty signal set.

24. `sigaddset`: Adds a signal to a signal set.

25. `kill`: Sends a signal to a process or a group of processes.

26. `exit`: Terminates the current process and returns an exit status.

### Processes Related Functions

27. `getcwd`: Gets the current working directory.

28. `chdir`: Changes the current working directory.

31. `execve`: Executes a program.

32. `dup`, `dup2`: Duplicates a file descriptor.

33. `pipe`: Creates a pipe for interprocess communication.

34. `opendir`, `readdir`, `closedir`: Functions for working with directories.

35. `strerror`: Retrieves the string description of an error code.

36. `perror`: Prints a descriptive error message to the console.

37. `isatty`: Checks if a file descriptor refers to a terminal.

38. `ttyname`: Returns the name of the terminal associated with a file descriptor.

39. `ttyslot`: Returns the slot number of the current terminal.

40. `ioctl`: Performs I/O control operations on a file descriptor.

41. `getenv`: Retrieves the value of an environment variable.

### Terminal Attributes

41. `tcsetattr`, `tcgetattr`: Functions for setting and getting terminal attributes.

### Terminal Capabilities

42. `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`: Functions for working with terminal capabilities in a termcap or terminfo database.

1. `tcsetattr`:
   - Description: `tcsetattr` is a C library function that sets terminal attributes, controlling various aspects of the terminal behavior.
   - Purpose: This function is used to modify the terminal settings, such as input modes, output modes, and control characters, based on the parameters provided in a `termios` structure.
   - Syntax: `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`
   - Arguments:
     - `fd`: The file descriptor representing the terminal whose attributes are to be modified.
     - `optional_actions`: It determines when the changes take effect. Possible values are `TCSANOW` (immediately), `TCSADRAIN` (after all output is transmitted), and `TCSAFLUSH` (after all output is transmitted, and discard pending input).
     - `termios_p`: A pointer to a `termios` structure containing the new terminal attributes.

2. `tcgetattr`:
   - Description: `tcgetattr` is a C library function that gets the current terminal attributes.
   - Purpose: This function is used to retrieve the current terminal settings and store them in a `termios` structure for further examination or modification.
   - Syntax: `int tcgetattr(int fd, struct termios *termios_p);`
   - Arguments:
     - `fd`: The file descriptor representing the terminal from which attributes are to be retrieved.
     - `termios_p`: A pointer to a `termios` structure where the retrieved terminal attributes will be stored.

3. `tgetent`:
   - Description: `tgetent` is a function used to access the terminal capability database.
   - Purpose: This function initializes the termcap database and retrieves the capability information for the specified terminal type. It is typically used with other termcap functions to get terminal-specific information.
   - Syntax: `int tgetent(char *bp, const char *name);`
   - Arguments:
     - `bp`: A buffer where the termcap database information will be stored.
     - `name`: The name of the terminal type for which you want to retrieve the capabilities.

4. `tgetflag`, `tgetnum`, `tgetstr`:
   - Description: These are termcap library functions used to extract specific capabilities from the terminal capability database.
   - Purpose: These functions allow you to retrieve specific terminal capabilities such as boolean flags, numeric values, and string capabilities like cursor movement, color codes, etc.
   - Syntax:
     - `int tgetflag(const char *id);`: Returns the value of the boolean capability specified by `id`.
     - `int tgetnum(const char *id);`: Returns the value of the numeric capability specified by `id`.
     - `char *tgetstr(const char *id, char **area);`: Returns the value of the string capability specified by `id`.

5. `tgoto`:
   - Description: `tgoto` is a termcap function used to construct a cursor control sequence for a given cursor position.
   - Purpose: This function constructs a terminal-specific control sequence for moving the cursor to a specified position on the screen.
   - Syntax: `char *tgoto(const char *cm, int col, int row);`
   - Arguments:
     - `cm`: The string capability representing cursor movement from the termcap database.
     - `col`: The target column for the cursor.
     - `row`: The target row for the cursor.

6. `tputs`:
   - Description: `tputs` is a termcap function used to send a terminal capability string to the terminal.
   - Purpose: This function is used to send terminal-specific control sequences (capabilities) directly to the terminal. It takes care of expanding padding, delays, and other terminal-specific processing.
   - Syntax: `int tputs(const char *str, int affcnt, int (*putc)(int));`
   - Arguments:
     - `str`: The terminal capability string to be sent to the terminal.
     - `affcnt`: The number of lines affected by the capability (used for scrolling).
     - `putc`: A function pointer that specifies how to output each character of the string. It is typically set to `putchar` for standard output.

These functions are part of the termcap/terminfo libraries in C and are used to interact with the terminal in a portable and terminal-independent manner. They allow you to control terminal behavior, display text, move the cursor, and manipulate terminal-specific capabilities without needing to know the details of each specific terminal type.


https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html
