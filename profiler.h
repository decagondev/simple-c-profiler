#include <assert.h>
#include <time.h>
#include <stddef.h>

#ifdef PROFILE

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

#define SUMMARY_CAPACITY 1024;
Entry summary[SUMMARY_CAPACITY];
size_t summanry_count = 0;

// =========== Implementation ==============

void begin_clock(const char *label)
{
    assert(clock_stack_count < CLOCK_STACK_CAPACITY);
    assert(summary_count < SUMMARY_CAPACITY);
}

void end_clock()
{

}