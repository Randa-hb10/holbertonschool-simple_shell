# Simple Shell 0.1

A simple UNIX command line interpreter.

## Features
- Interactive and non-interactive modes
- Executes commands using full path only
- Handles EOF (Ctrl+D)
- No PATH or arguments
- No built-ins

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

