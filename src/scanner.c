// scanner.c
// Recursively scans folders and analyzes only .c or .h files.

#include <stdio.h>              // for printf, snprintf
#include <string.h>             // for strstr (string matching)
#include <dirent.h>             // for working with directories (opendir, readdir)
#include <sys/stat.h>           // for stat() and checking file types

#include "scanner.h"            // includes the declaration of scan_directory()
#include "analyzer/analyzer.h"  // includes analyze_file() and AnalysisResult struct

void scan_directory(const char *path) {
    DIR *dir = opendir(path);           // Try to open the directory at the given path
    if (!dir) {                         // If it fails (e.g. path doesn't exist), print the error and stop
        perror("opendir failed");
        return;
    }

    struct dirent *entry;               // This will point to each entry (file/folder) in the directory

    while ((entry = readdir(dir)) != NULL) {     // Loop through all items in the directory
        if (entry->d_name[0] == '.') continue;   // Skip hidden files and . / .. folders

        char filepath[1024];                     // Buffer to store full path to the file
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name); 
        // Build the full path: foldername/filename

        struct stat info;                        // Struct to hold info about the file
        stat(filepath, &info);                   // Fill 'info' with details about filepath (file/folder)

        if (S_ISDIR(info.st_mode)) {             // If it's a directory
            scan_directory(filepath);            // Recurse into that subdirectory
        } else if (S_ISREG(info.st_mode)) {      // If it's a regular file (not a directory or special file)
            if (strstr(entry->d_name, ".c") || strstr(entry->d_name, ".h")) {
                // If the filename ends in .c or .h (i.e., a C source or header file)
                AnalysisResult dummy = {0};      // Create a dummy result struct (not used yet)
                analyze_file(filepath, &dummy);  // Call the analyzer function on that file
            }
        }
    }

    closedir(dir);                               // Done with the folder — clean up
}
