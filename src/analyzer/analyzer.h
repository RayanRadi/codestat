#ifndef ANALYZER_H
#define ANALYZER_H

#include <stdio.h>  // Required for FILE*

typedef struct {
    int total_lines;
    int code_lines;
    int blank_lines;
} AnalysisResult;

void analyze_file(const char *filepath, AnalysisResult *result);
void analyze_directory(const char *dir_path, FILE *json);
void print_total_loc_to_json(const char *summary_path);

#endif
