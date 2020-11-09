# Lab 1
## Synopsis
In this  exercise we aim to set up and get familiar with the local development environment we will be using in the course.

## Windows
You can use Windows throughout the course, but I encourage you to at least use a **GNU compiler**. The Windows-native GNU compiler is called **MinGW** - we will explain how to set it up. 

I would recommend using **VS Code** as an **IDE**. It is simple yet versatile and will serve you in this course as well in the future professional career.

Alternatively to MinGW, you can use any kind of Linux emulation, where you have access to the actual GCC compiler suite. By far the best option is **WSL** (see https://docs.microsoft.com/en-us/windows/wsl/install-win10), where you can have an Ubuntu running and direct access it through the IDE (VS Code) and the **Windows Terminal** (https://docs.microsoft.com/en-us/windows/terminal/get-started)

### Setup the Compiler

1. Download MinGW Package Manager from https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/
2. Install the package manager from step #1. Use the standard location, i.e. `C:\MinGW`
3. Open the MinGW package manager (it will be opened when the installer completes) and select the base and the c++ packages. From top menu, select "Apply Changes" and follow the steps.
4. You need to add MinGW binaries to the `Path` environment variable - this way you can use the compiler suite from the terminal. To do this, Type "Edit environment..." in your Windows Start and select "Edit user environment variables". Then select the "Path" for edit and add a new line with: `C:\MinGW\bin`
5. Open the terminal by typing "cmd".
6. Enter the following command:
```
g++
```
You should get an error message `fatal error`, which means the compiler suite is installed correctly.
### Setup IDE
Download Visual Studio Code from https://code.visualstudio.com and follow the installation steps. You can go with the defaults during hte installation process.

### Using the Terminal

#### Navigation
In the Windows terminal, you see the currently active path in the command prompt (the text preceding the `>`).

```cd folder``` - changes the active directory. 

You must provide a path to the directory you want to enter as a parameter. You can also provide a path, either absolute:

```cd C:\users\john\Documents\uni\lab01```

Or a relative path:

```cd Documents\uni\lab01```

If there are spaces or non-alphanumerical characters, you need to put quotes around the path:

```cd "C:\users\john\Documents\New Bulgarian University\lab01"```

# Compilation

```g++ myprogram.cpp -o myprogram.exe``` - compiles the source in `myprogram.cpp` into an executable file `myprogram.exe`

```-o``` instructs the compiler that `myprogram.exe` is the name of the output file that should be produced. It is optional, if you omit it the compiler will produce a file `a.exe`.

On Windows, it is mandatory to put the `.exe` extension.

You can specify additional flags to instruct the compiler further.

```g++ myprogram.cpp -o myprogram.exe -std=c++17``` - specifies that the C++17 standard should be used.

You can also compile multiple files, but more on that later in the course.

## Linux
TBD

## MacOS
TBD