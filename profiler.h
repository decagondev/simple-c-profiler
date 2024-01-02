#include <assert.h>
#include <time.h>
#include <stddef.h>


typdef struct {
    const char *label;
    double elapsed;
    size_t size;
} Entry;

typedef struct {
    struct timespec begin;
    Entry *entry;
} Clock;

#define CLOCK_STACK_CAPACITY 256
Clock clock_stack[CLOCK_STACK_CAPACITY];
size_t clock_stack_count = 0;
