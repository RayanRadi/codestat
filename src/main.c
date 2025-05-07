#include <stdio.h>
#include <stdlib.h>
#include "UsrCommands.h"
#include "scanner.h"
#include "analyzer/analyzer.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Auto-scan at startup
    scan_directory(argv[1]);
    print_total_loc_to_json("report.json");
    printf("Initial scan complete. JSON written to report.json.\n");

    // Enter interactive mode
    run_command_interface();

    return 0;
}
