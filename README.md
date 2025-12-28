# Simple Shell

A simple UNIX command line interpreter written in C.

## Features
- Interactive and non-interactive modes
- Executes commands with full path only
- Handles EOF (Ctrl+D)
- No built-ins
- No PATH handling

## Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

