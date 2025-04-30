// main.c
#include <stdio.h>    
#include "scanner.h"   

int main(int argc, char *argv[]) {
    printf("MAIN is running\n");

    if (argc < 2) {
        printf("No argument provided.\n");
        return 1;
    }

    printf("Calling scan_directory on: %s\n", argv[1]);
    scan_directory(argv[1]);
    return 0;
}
