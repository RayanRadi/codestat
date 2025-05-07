#include <stdio.h>
#include <string.h>
#include "analyzer.h"
#include "loc.h"
#include "complexity.h"  

static int total_loc = 0;
static int files_scanned = 0;
static FILE *json_out = NULL;

void analyze_file(const char *filepath, AnalysisResult *result) {
    LOCResult loc = count_loc(filepath);
    result->total_lines = loc.total_lines;
    result->code_lines = loc.code_lines;
    result->blank_lines = loc.blank_lines;

    const char* worst_complexity = get_worst_complexity(filepath);  // ← FIXED: define it before use

    if (!json_out) {
        json_out = fopen("report.json", "w");
        if (!json_out) {
            perror("fopen report.json");
            return;
        }
        fprintf(json_out, "[\n");
    }

    if (files_scanned > 0)
        fprintf(json_out, ",\n");

    fprintf(json_out,
        "  {\n"
        "    \"file\": \"%s\",\n"
        "    \"total_lines\": %d,\n"
        "    \"code_lines\": %d,\n"
        "    \"blank_lines\": %d,\n"
        "    \"worst_complexity\": \"%s\"\n"
        "  }",
        filepath, loc.total_lines, loc.code_lines, loc.blank_lines, worst_complexity
    );

    total_loc += loc.total_lines;
    files_scanned++;
}

void print_total_loc_to_json(const char *summary_path) {
    if (json_out) {
        fprintf(json_out, ",\n  {\n");
        fprintf(json_out,
            "    \"summary\": {\n"
            "      \"total_loc\": %d,\n"
            "      \"files_scanned\": %d\n"
            "    }\n"
            "  }\n");
        fprintf(json_out, "]\n");
        fclose(json_out);
        json_out = NULL;
    }
}
