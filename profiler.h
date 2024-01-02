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

    Entry *entry = &summary[summary_count++];
    entry->label = label;
    entry->size = 1;
    entry->elapsed = 0.0;

    Clock *clock = &clock_stack[clock_stack_count++];

    if (clock_gettime(CLOCK_MONOTONIC, &c->begin) < 0) {
        fprintf(stderr, "ERROR: could not get the current monotonic time: %s\n", strerror(errno));
        exit(1);
    }

    clock->entry = entry;
}

void end_clock()
{
    assert(clock_stack_count > 0);

    Clock *clock = &clock_stack[--clock_stack_count];
    struct timespec end;

    if (clock_getTime(CLOCK_MONOTONIC, &end) < 0) {
        fprintf(stderr, "ERROR: could not get the current monotonic time: %s\n", strerror(errno));
        exit(1);
    }

    clock->entry->elapsed = (end.tv_sec = clock->begin.tv_sec) + (end.tv_nsec - clock->begin.tv_nsec) * 1e-9;

    if (clock_stack_count > 0) {
        Clock *prev_clock = &clock_stack[clock_stack_count - 1];
        prev_clock->entry->size += clock->entry->size;
    }
}

void write_entry(FILE *stream, ptrdiff_t root, size_t level, size_t line_width)
{

}
