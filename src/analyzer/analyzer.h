// analyzer.h
// Declares the analyze_file() function and the AnalysisResult struct used to store file metrics.

#ifndef ANALYZER_H
#define ANALYZER_H

// Struct to hold analysis results (will be expanded later)
typedef struct {
    int loc;                   // lines of code (placeholder)
} AnalysisResult;

// Analyzes a single file and stores results in the given struct
void analyze_file(const char *filepath, AnalysisResult *result);

#endif
