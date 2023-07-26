0x16. C - Simple Shell Project Done By Olowe OluwaFunmibi and Memory Gwanuga
Simple Shell 🐚
A simple UNIX command interpreter 
Invocation 🚀
Usage: shellexe [filename]

To invoke shellexe, compile all .c files in the repository and run the resulting executable:

gcc *.c -o shellexe
./shellexe
Shellexe can be invoked both interactively and non-interactively. If shellexe is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:

$ echo "echo 'hello'" | ./shellexe
'hello'
$
PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

Command Execution 👍
After receiving a command, shellexe does tokenize it into words using " " as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. shellexe then proceeds with the following actions:

If the first character of the command is neither a slash (\) nor dot (.), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
If the first character of the command is none of a slash (\), dot (.), nor builtin, shellex searches each element of the PATH environmental variable for a directory containing an executable file by that name.
If the first character of the command is a slash (\) or dot (.) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.
Exit Status 👋
shellex returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

Signals ❗
When running in interactive mode, shellexe ignores the keyboard input Ctrl+c. Alternatively, an input of end-of-file (Ctrl+d) will exit the program.

User hits Ctrl+d in the third line.

$ ./shellex
$ ^C
$ ^C
$
Variable Replacement 💲
shellexe interprets the $ character for variable replacement.

$ENV_VARIABLE
ENV_VARIABLE is substituted with its value.

Example:

$ echo "echo $PWD" | ./shellex
/home/vagrant/ALX/simple_shell
$?
? is substitued with the return value of the last program executed.

Example:

$ echo "echo $?" | ./shellex
0
