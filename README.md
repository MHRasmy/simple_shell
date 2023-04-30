# Table of Contents

- [Table of Contents](#table-of-contents)
- [Simple Shell Project](#simple-shell-project)
- [Installation](#installation)
- [Usage](#usage)
- [Files](#files)
- [Contributing](#contributing)
- [Authors](#authors)

# Simple Shell Project

This is a simple UNIX command interpreter that can execute commands both interactively and from a file. This project was created as part of a programming assignment for the Holberton School's curriculum.

## Installation

To use the Simple Shell project, simply clone the repository from GitHub by running the following command in your terminal:

```shell
git clone https://github.com/MHRasmy/simple_shell.git
```

Once you have cloned the repository, navigate to the project directory by running:

```shell
cd simple_shell/
```

Compile the program by running:

```shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```

## Usage

To start the Simple Shell, run the following command in your terminal:

```shell
./shell
```

This will start the Simple Shell and you will see the prompt: `#cisfun$ ` For example if you want to list the files and directories in the current directory use `ls` like this:

```shell
#cisfun$ ls
```

write any commands to execute it. 
This will list the files and directories in the current directory.

You can also execute commands from a file by running:

```shell
./shell [filename]
```

For example, if you have a file called `commands` that contains a list of commands, you can run:

```shell
./shell commands
```

This will execute each command in the file.

Note that this shell doesn't support pipeline redirection.

## Files

- `shell.h`: contains all function prototypes and standard libraries.
- `shell.c`: contains the main function that runs the shell.
- `builtin.c`: contains the functions that execute built-in commands, e.g., `cd`, `exit`.
- `env.c`: contains functions to handle environment variables.
- `execute_command.c`: contains functions to execute commands shell.
- `parse_input.c`: contains functions to parse input commands.
- `print.c`: contains functions for printing output.
- `prompt.c`: contains functions to interpret shell commands;
- `run_commands_from_file.c`: contians functions to interpret commands from a file.
- `_free.c`: free memory allocated during runtime.
- `strings.c`: contains string manipulation functions.

## Contributing

Contributions to the Simple Shell project are welcome! To contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch with your changes: `git checkout -b <branch-name>`
3. Make your changes and test them thoroughly.
4. Commit your changes: `git commit -m "my commit message"`
5. Push your changes to your fork: `git push origin <branch-name>`
6. Create a pull request for your changes.

## Authors

This Simple Shell project was developed by:

- [Mohamed Rasmy](https://github.com/MHRasmy)
- [Denis Akushode](https://github.com/Delonix77)
