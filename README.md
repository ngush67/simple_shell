# SIMPLE SHELL 
Run as:<br>
```
gcc -Wall -Werror -Wextra -pedantic std=gnu89 *.c -o shell
```
In interactive mode:
```
$ ./shell
 $ /bin/ls
 shell main.c shell.c
 $ ls
 shell main.c shell.c
 $ exit
$
```
In non-interactive mode
```
$ echo "/bin/ls" | ./shell
shell main.c shell.c
$
$ cat test_ls
/bin/ls
/bin/echo hello
$
$ cat test_ls | ./shell
shell main.c shell.c
hello
```


Key man pages used or intended:
* `getline` / `strtok`
* `execve` / `fork` / `wait`
* `isatty`
* `exit`
* `access`
* `signal` / `kill`
* `stat`
* `fflush`
* `open` / `read` / `write` / `close`
* `malloc` / `free`
* `opendir` / `readdir` / `closedir`
* `chdir` / `getcwd`
* `perror`
<br>
<br>

## Features Implemented
Handles `PATH` directories i.e:<br>
>
```
$ ./shell
 $ /bin/ls
 shell main.c shell.c
 $
 $ ls
 shell main.c shell.c
```


Prints current environment with `env`<br>
>
```
$ ./shell
 $ env
 USER=blah
 LANGUAGE=en_US
 SESSION=ubuntu
 COMPIZ_CONFIG_PROFILE=ubuntu
 SHLVL=1
 HOME=/home/blah
```

Exits terminal<br>
>`exit [opt status]`<br>
`Ctrl+D`<br>
`Ctrl+C`


Sets an environment variable<br>
```
setenv [name] [value]
```

Deletes an environment variable<br>
```
unsetenv [name]
```

Changes directory, updates environment variable `PWD`<br>
```
cd [dir]
```

Commands separator `;`<br>

Shell logical operators `||` and `&&`<br>

Implements the `alias` built in command
> Usage: `alias [name[='value']]

Handles variable replacement with `$`
```
$ ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  snap  spool  tmp
$ echo $?
0
$ echo $$
5104
```

Handles Comments
```
$ echo $$ # ls -la
5114
```

Handles input passed as file
```
Usage: shell [filename]
$ cat commands
ls
echo hello
env
$
$ ./shell commands
shell main.c shell.c
hello
USER=blah
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/blah
```
