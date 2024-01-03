# simple-c-profiler
Simple C Profiler to time functions in C Programs

## to Build in linux
you can add this header file to a c file that you wish to profile and do a `#define PROFILE` inside the c file.

```c
#include "profiler.h"
#define PROFILER
```

then add a `begin_clock("Some Title);` at the begining of a section you want to profile and any subsiquent segments. And add a `end_clock()` to the end of the segment you wish to profile.

then compile your application as normal for example

## Linux
```bash
gcc -o main main.c
```

## Windows
```bash
cl main.c
```

## MacOS
```bash
clang -o main main.c
```

## Compile in linux for windows (NixOS)
for this use the provided shell.nix file to compile with minGW
**if you have a NixOS install you will need to make sure you have Multiplatform support in your `configuration.nx` file.**

```
  # Multi-platform Support
  boot.binfmt.emulatedSystems = [
    "x86_64-windows"
  ];
```

**then you can got in to a nix shell, and build the `dcat.exe`**
```bash
nix-shell
x86_64-w64-mingw32-gcc -o main.exe main.c
./main.exe
```