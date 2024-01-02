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

```bash
gcc -o main main.c
```
