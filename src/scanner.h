// scanner.h
// Declares the scan_directory() function used to recursively scan folders for code files.

#ifndef SCANNER_H
#define SCANNER_H

// Scans a directory and calls analyze_file() on each .c or .h file found
void scan_directory(const char *path);

#endif
