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
    fprintf(stream, "%*s%-*s%.9lf secs\n", (int) level * 2, "", (int) line_width - (int) level * 2, summary[root].label, summary[root].elapsed);
    size_t size = summary[root].size - 1;
    ptrdiff_t child = root + 1;

    while (size > 0) {
        write_entry(stream, child, level + 1, line_width);
        size -= summary[child].size;
        child += summary[child].size;
    }
}

void write_summary(FILE *stream, size_t line_width)
{
     ptrdiff_t root = 0;

    while ((size_t) root < summary_count) {
        write_entry(stream, root, 0, line_width);
        root += summary[root].size;
    }
}

size_t establish_entry_line_width(ptrdiff_t root, size_t level)
{
    size_t line_width = 2 * level + strlen(summary[root].label);
    ptrdiff_t child = root + 1;

     while (size > 0) {
        size_t entry_line_width = establish_entry_line_width( child, level + 1);

        if (entry_line_width > line_width) {
            line_width = entry_line_width;
        }

        size -= summary[child].size;
        child += summary[child].size;
    }
    return line_width;
}

size_t establish_line_width()
{
    size_t line_width = 0;






    return line_width;

}

void clear_summary()
{
    clock_stack_count = 0;
    summanry_count = 0;
}


void dump_summary(FILE *stream)
{
    
}

#else
#define begin_clock(...)
#define end_clock(...)
#define dump_summary(...)
#define clear_summary(...)
#endif