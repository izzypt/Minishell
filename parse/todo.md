
[] $?
saves the exit status of the last executed command or process
- 0: SUCCES
- 1: generic or unspecified error occured
- 2: indictae syntax error in command
- 126: command was found but could not be executed due to insufficient permission or other execution related issues
- 127: command was not found
- 127-255: If a signal Kill or interrupte the command 127 + signal

[x] special char at beginning
[x] pipes and redirections behind each other
[x] env var with num and _

[x] change 'env' to env variable in parser?
[x] take care of following env variable:
	[x] $11askjdhakd -> $1 is looked up, rest is ignored
	[x] $sadlj123516723 -> full string is looked up
	[x] $USER$USER

[x] empty env_var

[] Pipe at end asking for more prompt

[] ERROR message
	[] redirections at end
	[x] 2 special chars behind each other

[x] free token (scanner_split.c)
[x] free list after each readline
[x] free paths (paths.c)

[] echo in the middle
	ex. cat echo test.txt

[x] Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
