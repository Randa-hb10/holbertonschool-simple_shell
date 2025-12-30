# Simple Shell (hsh)

## 📌 Description
This project is a simple implementation of a UNIX command line interpreter (shell), written in **C**, as part of the Holberton School curriculum.

The shell mimics the behavior of `/bin/sh` by:
- Reading user input
- Parsing commands
- Executing programs using system calls
- Handling interactive and non-interactive modes

---

## 👥 Authors
- **Mohammed Aloufi**
- **Baeshen Hussain Randa**

---

## 🎯 Learning Objectives
At the end of this project, we are able to explain:

- How a UNIX shell works internally
- How processes are created and managed
- What `fork`, `execve`, and `wait` do
- The difference between system calls and functions
- How the `PATH` environment variable works
- What `PID` and `PPID` are
- How environment variables are accessed and used
- How EOF (End Of File) is handled
- Memory management in C (avoiding memory leaks)

---

## 🛠 Requirements
- OS: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Compilation flags:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


Coding style: Betty

No memory leaks allowed

Maximum 5 functions per file

Header files must be include guarded

⚙️ Compilation

To compile the shell, run:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

🚀 Usage

Interactive Mode
$ ./hsh
($) ls
($) pwd
($) exit

Non-Interactive Mode
$ echo "ls" | ./hsh

$ cat file.txt | ./hsh

Features

Executes commands with absolute paths

Executes commands found in the PATH

Handles interactive and non-interactive modes

Built-in command:

exit

Proper error handling (command not found)

Handles EOF (Ctrl + D)

No memory leaks

Pipes (|)

Redirections (>, <, >>)

Environment built-ins (env, setenv, unsetenv)

Aliases

Command chaining (&&, ||)

🧠 How It Works (High Level)

Display prompt (interactive mode only)

Read input using getline

Tokenize input using strtok

Create a child process using fork

Execute command using execve

Parent process waits using wait

Loop until exit or EOF

Project Structure
.
├── hsh
├── main.c
├── shell.c
├── parser.c
├── executor.c
├── utils.c
├── shell.h
└── README.md

⚠️ Error Handling

The shell prints errors exactly like /bin/sh, except that the program name matches argv[0].

Example:

./hsh: 1: qwerty: not found

🧪 Testing

Examples:

$ echo "/bin/ls" | ./hsh
$ cat test_file | ./hsh


Memory checks:

valgrind ./hsh

📚 Allowed Functions

All functions from <string.h>

fork, execve, wait

getline, malloc, free

access, stat

write, read, printf

perror

chdir

signal

And others specified in the project requirements

🏁 Conclusion

This project provides a deep understanding of how UNIX shells work and strengthens low-level programming skills in C, especially process management and system calls.

📄 License

This project is for educational purposes only
