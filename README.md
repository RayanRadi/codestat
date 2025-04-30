# codestat
codestat is a fast, modular command-line tool written in C that recursively scans a codebase and analyzes .c, .h, and (soon) Java and Python files. It provides raw metrics like total lines of code, function counts, and TODOs, with future support for detecting structural issues, code smells, and violations of object-oriented principles like missing polymorphism or poor modularity. Designed to be lightweight yet extensible, codestat will also include an AI-powered Python layer that parses reports and provides intelligent suggestions for improving code quality, maintainability, and design.

⚙️ Build & Run
bash
Copy
Edit
# 🔧 Compile the project
make

# 🚀 Run codestat on a target codebase
./codestat path/to/codebase
<details> <summary>💡 Example Output</summary>
text
Copy
Edit
Analyzed: path/to/codebase/main.c
Analyzed: path/to/codebase/utils.h
Analyzed: path/to/codebase/submodule/parser.c
</details>
✅ Only .c, .h (and soon .java, .py) files are analyzed
🧠 Output will expand as more features are added (LOC, TODOs, complexity, AI suggestions)
