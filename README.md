# minishell
HIVE School project. The aim is to create a basic UNIX command line interpreter. As for every Hive project, the program should not have any memory leaks and it should not crash unexpectedly.

Allowed functions to use in this project:
- malloc, free
- access
- open, close, read, write
- opendir, readdir, closedir
- getcwd, chdir
- stat, lstat, fstat
- fork, execve
- wait, waitpid, wait3, wait4
- signal, kill
- exit

All other functions, along with the libft are coded by yours truly.


This project comes with a makefile, with the following rules:
- make (will compile the program), gives you the executable minishell
- make clean (removes all of the object files)
- make fclean (removes libraries, o-files and the executable)
- make re (executes make fclean and make)

To launch the program;
1. Copy the repo and then cd /repo
2. make
3. ./minishell
4. Voila, you're now using my basic version of a shell.
5. To exit the program, you can just type in exit end press enter.

Mandatory part for the project:
- You must program a mini UNIX command interpreter.
- This interpreter must display a prompt (a simple "$> " for example) and wait till you type a command line, validated by pressing enter.
- The prompt is shown again only once the command has been completely executed.
- The command lines are simple, no pipes, no redirections or any other advanced functions.
- The executable are those you can find in the paths indicated in the PATH variable.
- In cases where the executable cannot be found, it has to show an error message and display the prompt again.
- You must manage the errors without using errno, by displaying a message adapted to the error output.
- You must deal correctly with the PATH and the environment (copy of system char **environ).
- You must implement a series of builtins: echo, cd, setenv, unsetenv, env, exit.
- You can choose as a reference whatever shell you prefer.
- You must manage expansions $ and  ̃

Additional features of my minishell:
- CTRL + C does not terminate the process
- The separation of commands with ';', eg. echo "Hello World" ; ls , will print out Hello World and then execute ls.
