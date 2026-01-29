*This project has been created as part of the 42 curriculum by muhakhan and okhan.*

# Minishell - As Beautiful as a Shell

## Description
Minishell is a project from the 42 curriculum that challenges students to create their own shell from scratch. The goal is to replicate the core functionality of Bash, including command execution, pipes, redirections, and environment variable management. This project provides deep insights into process creation (`fork`), process replacement (`execve`), and inter-process communication (`pipe`).

### Key Features
- **Interactive Prompt**: A functional command line with history support.
- **Command Execution**: Searching and executing binaries via the `PATH` variable or absolute/relative paths.
- **Builtins**: Implementation of `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Pipelines**: Connecting multiple commands using the `|` operator.
- **Redirections**:
  - `<` : Input redirection.
  - `>` : Output redirection (truncate).
  - `>>` : Output redirection (append).
  - `<<` : Heredoc (with signal handling).
- **Environment Management**: Dynamic handling of environment variables through a linked list.
- **Signal Handling**: Proper response to `Ctrl-C` (SIGINT), `Ctrl-D` (EOF), and `Ctrl-\` (SIGQUIT).

## Project Structure
The project is organized into modular components as follows:

- **include/**: Contains the `minishell.h` header file.
- **libft/**: The custom C library used throughout the project.
- **src/**:
  - **builtin/**: Implementation of internal shell commands.
  - **env/**: Environment variable initialization and utilities.
  - **execution/**: Logic for process management, pipes, and redirections.
  - **get_next_line/**: Utility for reading input.
  - **parser/**: Tokenization, expansion, and command parsing.
  - **signals/**: Signal handling logic.
  - **utils/**: General helper functions and cleanup.
  - **main.c**: The entry point of the shell.
- **Makefile**: Script for compiling the project.
- **README.md**: Project documentation.

## Instructions

### Compilation
To compile the project, run the following command in the root directory:
make

This will generate the `minishell` executable.

### Execution
Run the shell using:
./minishell

## Resources
- **Documentation**: 
  - [GNU Bash Manual](https://www.gnu.org/software/bash/manual/)
  - [Linux Programmer's Manual (man pages)](https://man7.org/linux/man-pages/)
- **Articles**: 
  - "Writing Your Own Shell" tutorials.
  - 42 Project Peer-to-Peer documentation.

### AI Usage
AI was used to assist with:
- Refactoring long functions to comply with Norminette rules.
- Suggesting helper functions to reduce code duplication.
- Debugging compilation and linking errors after splitting files.
- Reviewing and optimizing error handling logic for external command execution.

AI assistance was strictly limited to guidance and refactoring, and the core logic, design, and implementation of the shell were done manually.