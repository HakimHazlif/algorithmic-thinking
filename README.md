# C Compilation and Execution Guide

## Dirctory Workflow

The project uses two main directories:

| Directory      | Purpose                                        |
| -------------- | ---------------------------------------------- |
| `first-tries/` | Initial problem-solving attempts from the book |
| `solutions/`   | Refined solutions after reviewing book         |
| `bin/`         | compiled binary files                          |

> Note: The `bin/` directory is optional. It collects binary files in one place and makes it easier to ignore them in Git.

Both directories `first-tries/` and `solutions/` contain similar file structures for each problem.

### Tips

- Target a specific directory: Replace `*/` with `first-tries/` or `solutions/`

- Check for warnings: Add `-Wall` to see compiler warnings

- Keep input files: Ensure `.txt` files are in the same directory as the source

## Basic Commands

### Compile Only

Compile `main.c` into an executable named `main` inside the `bin/` directory:

```bash
gcc main.c -o bin/main
```

### Run Only

Execute the compiled program:

```bash
./bin/main
```

### Compile and Run (One-liner)

Compile then immediately run the program:

```bash
gcc main.c -o bin/main && ./bin/main
```

### Compile and Run from a Specific Directory

From `first-tries/`:

```bash
gcc first-tries/file.c -o bin/main && ./bin/main < first-tries/file.txt
```

From `solutions/`:

```bash
gcc solutions/file.c -o bin/main && ./bin/main < solutions/file.txt
```

With compiler warnings:

```bash
gcc -Wall first-tries/file.c -o bin/main && ./bin/main < first-tries/file.txt
```

## Specific Use Cases

### Food Lines Problem

Compile `foodLines.c` and run it with input from `foodLines.txt`:

```bash
gcc */foodLines.c -o bin/main && ./bin/main < */foodLines.txt
```

### Snowflakes Problem

Compile `snowflakes.c` and run it with input from `snowflakes.txt`:

```bash
gcc */snowflakes.c -o bin/main && ./bin/main < */snowflakes.txt
```
