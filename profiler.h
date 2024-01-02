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