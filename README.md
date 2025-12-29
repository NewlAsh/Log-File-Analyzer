# Log Analyzer in C++

A beginner-to-intermediate level C++ project that analyzes log files using
Object-Oriented Programming (OOP), STL containers, and file handling.

## 📌 Features
- Parses log files line by line
- Counts log levels (INFO, ERROR, WARNING, etc.)
- Detects the most frequent log message
- Generates a detailed summary report (`summary.txt`)
- Uses constructors for automatic log analysis (RAII style)

## 🧠 Concepts Used
- Classes & Encapsulation
- Constructors
- `ifstream` / `ofstream`
- `vector` and `map`
- String parsing
- Frequency analysis

## 📂 Files
- `main.cpp` → Source code
- `log.txt` → Sample input log file
- `summary.txt` → Generated analysis report

## ▶️ How to Run
```bash
g++ main.cpp -o log_analyzer
./log_analyzer
