# codestat
codestat is a fast, modular command-line tool written in C that recursively scans a codebase and analyzes .c, .h, and (soon) Java and Python files. It provides raw metrics like total lines of code, function counts, and TODOs, with future support for detecting structural issues, code smells, and violations of object-oriented principles like missing polymorphism or poor modularity. Designed to be lightweight yet extensible, codestat will also include an AI-powered Python layer that parses reports and provides intelligent suggestions for improving code quality, maintainability, and design.

Compile the project using make:

bash
Copy
Edit
make
Run codestat on any folder containing .c/.h files:

bash
Copy
Edit
./codestat path/to/codebase
You’ll see output like:

vbnet
Copy
Edit
Analyzed: path/to/codebase/main.c
Analyzed: path/to/codebase/utils.h
