# Lazy merged list iterator

This repository contains a C++ implementation of a lazy iterator that merges three sorted, disjoint integer lists. The iterator provides elements in ascending order on-demand, without allocating memory for a new combined list.

## Task
### Given:
Three lists of integers sorted in ascending order. 
Each integer appears only once in all 3 lists, that is, if it appears in one list, it does not appear in two other lists.
So effectively we have ascending sequence of numbers broken into three disjoint lists.

### To do:
Implement an iterator function GetNext() that returns the next element in the ascending sequence of numbers that is the union of these 3 lists.
Do not build the union explicitly, iterate over the three given lists.

### Example of input data:
*   **List 1**: 1,8,15,16,35
*   **List 2**: 2,7,12,63
*   **List 3**: 10,13,14,42

### Example of output data:
`Merged sequence: 1 2 7 8 10 12 13 14 15 16 35 42 63 `

### Requirements:
Program must be written in C++.

## Building and Running the Project

This project is configured for building and debugging within Visual Studio Code using CMake.

### Prerequisites

*   **C++ Compiler**: A modern C++ compiler (e.g., [MinGW-w64](https://www.mingw-w64.org/) for Windows, GCC for Linux, Clang for macOS).
*   **CMake**: Version 3.10 or newer.
*   **Visual Studio Code**: The code editor.
*   **C/C++ Extension for VS Code**: The official Microsoft C/C++ extension for IntelliSense and debugging.

### Steps to Run in VS Code

1.  Open the project folder in Visual Studio Code.
2.  Open the Command Palette (`Ctrl + Shift + P` or `View -> Command Palette...`).
3.  Type `Tasks: Run Task` and select it.
4.  Choose **1. CMake Configure** to generate the build system files.
5.  Run the task **2. CMake Build** to compile the project.
6.  Run the task **3. Run Executable** to see the output of the main program.

### How to Debug

1.  Open any `.cpp` file (e.g., `source/main.cpp`) and set a breakpoint by clicking to the left of a line number.
2.  Switch to the "Run and Debug" view on the sidebar (`Ctrl + Shift + D`).
3.  Select **Debug Exe** from the configuration dropdown at the top.
4.  Press the green "Start Debugging" button (or `F5`). The build task will run, and the debugger will start, stopping at your breakpoint.
