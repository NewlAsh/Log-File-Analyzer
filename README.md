# Log File Analyzer (C++)

A C++ project that reads and analyzes structured log files to generate a detailed summary report.  
The project demonstrates **file handling, STL usage, object-oriented design, and data analysis** in C++.

---

## 📌 Project Overview

This Log File Analyzer processes a log file containing:
- timestamps
- log levels (INFO / WARN / ERROR)
- log messages  

It extracts useful insights such as:
- log time range
- frequency of each log level
- most frequent messages
- timestamps of WARN and ERROR logs
- a final summarized report saved to a text file

---

## 🧱 Project Structure

- **`logEntry` class**
  - Represents a single log entry
  - Stores:
    - timestamp
    - log level
    - log message

- **`logAnalyzer` class**
  - Reads the log file
  - Parses each line
  - Maintains counters using STL containers
  - Generates a well-structured summary report

---

## 🛠 Concepts & Technologies Used

- C++ (STL)
- File handling (`ifstream`, `ofstream`)
- Object-Oriented Programming
- `vector`, `map`
- String parsing
- Clean separation of responsibilities between classes

---

## 📄 Input Format (`log.txt`)

Each line in the log file must follow this exact structure:


### Description:
- `YYYY-MM-DD HH:MM:SS` → Timestamp (19 characters)
- `LEVEL` → Log level (`INFO`, `WARN`, or `ERROR`)
- `Message` → Description of the event (can contain spaces)


> ⚠️ Note:  
> - Timestamp must always be at the beginning of the line  
> - Log level and message must be separated by a single space  
> - Each log entry should be on a new line





---

## 📤 Output (`summary.txt`)

The generated summary includes:
- Log time range (first to last timestamp)
- Count of each log level
- Count of each unique message
- Most frequent log level and message
- Timestamps where WARN and ERROR occurred
- Actionable warnings for repeated ERROR/WARN logs

---

## 🚀 How to Run

1. Clone the repository
2. Place your `log.txt` file in the same directory
3. Compile the code:
   ```bash
   g++ log_analyzer.cpp -o log_analyzer

./log_analyzer
