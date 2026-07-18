# C Compilation and Execution Guide

## Basic Commands

### Compile Only

Compile `main.c` into an executable named `main`:

```bash
gcc main.c -o main
```

### Run Only

Execute the compiled program:

```bash
./main
```

### Compile and Run (One-liner)

Compile then immediately run the program:

```bash
gcc main.c -o main && ./main
```

## Specific Use Cases

### Food Lines Problem

Compile `foodLines.c` and run it with input from `foodLines.txt`:

```bash
gcc foodLines.c -o main && ./main < foodLines.txt
```
