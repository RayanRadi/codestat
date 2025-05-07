// function_count.c
// Detects and counts functions within a C source/header file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNCS 100
#define MAX_LINE 1024

typedef struct {
    char name[128];
    char complexity[16];
} FunctionInfo;

static int detect_recursion(const char *func_name, const char *body) {
    return strstr(body, func_name) != NULL;
}

static const char* estimate_complexity(const char *body, const char *func_name) {
    int for_loops = 0;
    int nested_loops = 0;
    int in_loop = 0;
    int recursion = detect_recursion(func_name, body);

    const char *p = body;
    while (*p) {
        if (strncmp(p, "for", 3) == 0 || strncmp(p, "while", 5) == 0) {
            for_loops++;
            if (in_loop) nested_loops++;
            in_loop = 1;
        } else if (*p == '}') {
            in_loop = 0;
        }
        p++;
    }

    if (recursion) return "O(2^n)";
    if (nested_loops >= 1) return "O(n^2)";
    if (for_loops >= 1) return "O(n)";
    return "O(1)";
}

void analyze_file_complexity(const char *filepath) {
    FILE *f = fopen(filepath, "r");
    if (!f) {
        perror("fopen");
        return;
    }

    char line[MAX_LINE];
    char func_body[10000] = {0};
    FunctionInfo functions[MAX_FUNCS];
    int func_count = 0;
    int recording = 0;
    int brace_count = 0;

    char current_func[128] = "";

    while (fgets(line, sizeof(line), f)) {
        if (!recording) {
            // crude function detection
            if (strstr(line, "(") && strstr(line, ")") && strchr(line, '{')) {
                sscanf(line, "%127s", current_func);
                recording = 1;
                brace_count = 1;
                strcpy(func_body, line);
            }
        } else {
            strcat(func_body, line);
            for (int i = 0; line[i]; i++) {
                if (line[i] == '{') brace_count++;
                else if (line[i] == '}') brace_count--;
            }

            if (brace_count == 0) {
                // End of function body
                strcpy(functions[func_count].name, current_func);
                strcpy(functions[func_count].complexity, estimate_complexity(func_body, current_func));
                func_count++;
                recording = 0;
                func_body[0] = '\0';
            }
        }
    }

    fclose(f);

    // Determine worst-case
    const char *ranking[] = { "O(1)", "O(n)", "O(n^2)", "O(2^n)" };
    int worst_rank = 0;

    for (int i = 0; i < func_count; i++) {
        int rank = 0;
        while (rank < 4 && strcmp(functions[i].complexity, ranking[rank]) != 0) rank++;
        if (rank > worst_rank) worst_rank = rank;
    }

    printf("File: %s\n", filepath);
    for (int i = 0; i < func_count; i++) {
        printf("  Function: %s - Complexity: %s\n", functions[i].name, functions[i].complexity);
    }
    printf("  >> Worst-case in file: %s\n\n", ranking[worst_rank]);
}
