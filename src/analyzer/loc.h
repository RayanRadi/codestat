// loc.h
// Header for LOC counting module. Declares LOCResult and count_loc().

#ifndef LOC_H
#define LOC_H

typedef struct {
    int total_lines;
    int code_lines;
    int blank_lines;
} LOCResult;

LOCResult count_loc(const char *filepath);

#endif
