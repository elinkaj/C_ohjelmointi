// debug.h
#ifndef DEBUG_H
#define DEBUG_H

void set_debug_level(int debug_level);
int dprintf(int debug_level, const char *fmt, ...);

#endif

// debug.c
#include <stdio.h>
#include <stdarg.h>

static int debug_level = 0;

void set_debug_level(int level) {
    debug_level = level;
}

int dprintf(int level, const char *fmt, ...) {
    if (level <= debug_level) {
        va_list args;
        va_start(args, fmt);
        fprintf(stderr, "[DBG%d] ", level);
        int ret = vfprintf(stderr, fmt, args);
        va_end(args);
        return ret;
    }
    return 0;
}

// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int debug_level;

    printf("Enter debug level (0 - 4): ");
    scanf("%d", &debug_level);
    set_debug_level(debug_level);

    for (int i = 0; i < 5; i++) {
        int random_level = rand() % 5;
        dprintf(random_level, "Message %d with debug level %d\n", i + 1, random_level);
    }

    return 0;
}
