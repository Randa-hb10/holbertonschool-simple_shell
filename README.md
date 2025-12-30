# 🐚 Simple Shell (hsh)
A minimal UNIX command line interpreter written in C.

---

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
- **Randa Baeshen**

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


* Coding style: Betty

* No memory leaks allowed

* Maximum 5 functions per file

* Header files must be include guarded

⚙️ Compilation

To compile the shell, run:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

🚀 Usage

📄 Interactive Mode
$ ./hsh
($) ls
($) pwd
($) exit

📄 Non-Interactive Mode
$ echo "ls" | ./hsh

$ cat file.txt | ./hsh


## ✨ Features

✔ Executes commands with absolute paths

✔ Executes commands found in the PATH

✔ Handles interactive and non-interactive modes

✔ Built-in command:

- `exit` — exits the shell

✔ Proper error handling (command not found)

✔ Handles EOF (Ctrl + D)

✔ No memory leaks

❌ Not Supported

* Pipes (|)

* Redirections (>, <, >>)

* Environment built-ins (env, setenv, unsetenv)

* Aliases

* Command chaining (&&, ||)

## ⚙️ How It Works

- Display prompt (interactive mode only)

- Read input using getline

- Tokenize input using strtok

- Create a child process using fork

- Execute command using execve

- Parent process waits using wait

- Loop until exit or EOF

🗂 Project Structure

holbertonschool-simple_shell/

| File               | Purpose                                                |
| ------------------ | ------------------------------------------------------ |
| AUTHORS            | Lists all contributors to the project                  |
| man_1_simple_shell | Manual page for the simple shell                       |
| README.md          | Project documentation, usage, examples, and features   |
| main.c             | Program entry point                                    |
| parser.c           | Handles input parsing and tokenization                 |
| execute.c         | Responsible for process creation and command execution |
| path.c             | Handles PATH resolution and command lookup             |
| string_function.c  | Contains custom string helper functions                |
| utils.c            | General utility helper functions                       |
| shell.h            | Header file containing function prototypes and macros  |
| hsh                | Compiled shell executable                              |



📌 Project Tasks (Development Stages)
0. Betty would be proud

Write clean, readable, and well-structured code that passes all Betty coding style checks.

1. Simple shell 0.1

- Display a prompt and wait for user input

- Execute simple commands (one word, no arguments)

- Handle end-of-file condition (Ctrl + D)

2. Simple shell 0.2

- Handle command lines with arguments

3. Simple shell 0.3

- Handle the PATH environment variable

- fork() is not called if the command does not exist

4. Simple shell 0.4

- Implement the exit built-in command

- Usage: exit

- No arguments are handled

5. Simple shell 0.4+

- Implement the env built-in command

- Prints the current environment

- No arguments are handled


⚠️ Error Handling

The shell prints errors exactly like /bin/sh, except that the program name matches argv[0].

Example:

./hsh: 1: qwerty: not found

🧪 Testing

Examples:

$ echo "/bin/ls" | ./hsh
$ cat test_file | ./hsh


## 🧠Memory checks:

valgrind ./hsh

📚 Allowed Functions

✔ All functions from <string.h>

✔ fork, execve, wait

✔ getline, malloc, free

✔ access, stat

✔ write, read, printf

✔ perror

✔ chdir

✔ signal

✔ And others specified in the project requirements

🏁 Conclusion

This project provides a deep understanding of how UNIX shells work and strengthens low-level programming skills in C, especially process management and system calls.


