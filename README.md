# Binary Search Tree Implementation in C

This project implements a **Binary Search Tree (BST)** in C, supporting operations like insertion, deletion, find and pirnt.

---

## **Prerequisites**

To compile and run this program, you need:
1. **GCC (GNU Compiler Collection)** installed on your system.
2. GCC should support the **C99 standard** for compatibility with modern C features.

---

## **How to Build and Run**

This project includes a Makefile to simplify the build process. The Makefile supports the following commands:

### **1. Build the Project**
To compile the program, run:

~$ make

This will:

Compile the bst.c source file with the following flags

-Wall:     Enables most common warnings.

-Wextra:   Enables additional, stricter warnings.

-pedantic: Enforces strict adherence to the C standard.

-std=c99:  Specifies the C99 standard for compilation.

Generate the executable named bst.

2. Run the Program

3. After building the project, you can run the program with

~$ make run

This will execute the bst binary and display the output.

5. Clean the Build Files

6. To clean up the compiled files and binaries, run
~$ make clean

This will:

Remove the bst executable.

Delete any intermediate object files (.o).

File Structure

bst.c       # Source code of the Binary Search Tree implementation

Makefile    # Automates the build, run, and clean processes

README.md   # Documentation for the project

Contributing

Feel free to fork this repository, make improvements, and submit a pull request.
