# 🔍 Advanced String Matching Algorithms Comparison

![Project Banner](https://via.placeholder.com/800x200.png?text=String+Matching+Algorithms+Comparison)

> An in-depth exploration and comparison of Brute-force, Horspool's, and Boyer-Moore string matching algorithms.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C99](https://img.shields.io/badge/C-99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/yourusername/string-matching-comparison)

---

## 📚 Table of Contents

1. [🌟 Project Overview](#-project-overview)
2. [🧠 Algorithms Implemented](#-algorithms-implemented)
3. [🛠️ Detailed Implementation](#️-detailed-implementation)
4. [🚀 How to Compile and Run](#-how-to-compile-and-run)
5. [📊 Input Types and Generation](#-input-types-and-generation)
6. [📋 Output Details](#-output-details)
7. [📈 Performance Metrics and Analysis](#-performance-metrics-and-analysis)
8. [⚡ Optimization Techniques](#-optimization-techniques)
9. [⚠️ Known Limitations and Edge Cases](#️-known-limitations-and-edge-cases)
10. [🔮 Future Improvements](#-future-improvements)
11. [🤝 Contributing](#-contributing)
12. [📄 License](#-license)

---

## 🌟 Project Overview

This project is an advanced implementation of string matching algorithms, designed for the CSE 2046/2246 Analysis of Algorithms course (Spring 2023). We dive deep into the world of pattern matching, exploring efficiency and performance across various scenarios.

### Key Objectives:
- 🔬 Implement and optimize three distinct string matching algorithms
- 🏋️ Stress-test algorithms with diverse input types
- 🎨 Highlight pattern occurrences in HTML with efficiency
- 📊 Generate comprehensive performance analytics
- 🧠 Provide insights into algorithmic behavior under various conditions

---

## 🧠 Algorithms Implemented

### 1. Brute-force Algorithm
- **Time Complexity**: `O(nm)`
- **Space Complexity**: `O(1)`
- **Key Features**:
  - 🔨 Simple, straightforward implementation
  - 🚫 No preprocessing required
  - ⚠️ Inefficient for large inputs

### 2. Horspool's Algorithm
- **Time Complexity**: Average `O(n)`, Worst `O(nm)`
- **Space Complexity**: `O(k)`, where k is alphabet size
- **Key Features**:
  - 🏃‍♂️ Uses bad character rule for efficient skipping
  - 🔧 Preprocessing builds bad character table
  - 🚀 Faster than brute-force for larger alphabets

### 3. Boyer-Moore Algorithm
- **Time Complexity**: Average `O(n/m)`, Worst `O(nm)`
- **Space Complexity**: `O(k + m)`
- **Key Features**:
  - 🧠 Employs bad character and good suffix rules
  - 🔬 Complex preprocessing phase
  - ⚡ Often fastest for large alphabets and patterns

---

## 🛠️ Detailed Implementation

Our main program (`main.c`) is structured for maximum efficiency:

1. 📂 **File Reading**: Utilizes `fread` for speedy I/O
2. 🔧 **Preprocessing**: 
   - Horspool: Builds bad character table
   - Boyer-Moore: Constructs bad character and good suffix tables
3. 🔍 **Pattern Matching**: Implements all algorithms with detailed comments
4. 🖨️ **Output Generation**: Employs efficient string manipulation
5. ⏱️ **Performance Measurement**: Uses high-resolution timers

### Key Optimizations:
- 🔢 Bitwise operations for faster comparisons
- 💾 Cache-friendly data structures
- 🧬 Efficient memory management

---

## 🚀 How to Compile and Run

1. **Compile with optimizations:**
   ```bash
   gcc -O3 -march=native -o string_matcher main.c
   ```

2. **Run the program:**
   ```bash
   ./string_matcher <html_filename> <pattern>
   ```

3. **Batch processing:**
   ```bash
   ./run_experiments.sh
   ```

---

## 📊 Input Types and Generation

### Type 1: HTML files with English text
- 🌐 Sourced from real web pages
- 📏 Patterns: English words (3-15 characters)
- 🔧 Generation:
  1. Fetch HTML from popular sites
  2. Clean and normalize structure
  3. Ensure 1MB+ file size

### Type 2: HTML files with random bit-strings
- 🎲 Generated via `inputCreatorTypeTwo.c`
- 📏 Patterns: Random bit-strings (8-64 bits)
- 🔧 Generation:
  1. Use Mersenne Twister RNG
  2. Generate biased bit-strings
  3. Embed in valid HTML

---

## 📋 Output Details

1. **🖍️ Highlighted HTML**:
   - Uses `<mark></mark>` tags
   - Preserves original HTML structure
   - Employs in-place string manipulation

2. **💻 Console Output**:
   - 📊 Bad Symbol Table
   - 📈 Good Suffix Table
   - 🔢 Occurrence count
   - 🧮 Comparison count
   - ⏱️ Running time (ms)

3. **📝 Log File**:
   - 📊 Input file statistics
   - 🔍 Step-by-step execution details
   - 💾 Memory usage data

---

## 📈 Performance Metrics and Analysis

We measure and analyze:

1. 🔢 **Character comparisons**
2. ⏱️ **Running time (ms)**
3. 🎯 **Pattern occurrences**
4. 🔧 **Preprocessing time**
5. 💾 **Memory usage**

### Analysis Techniques:
- 📊 Statistical analysis across multiple runs
- 📉 Performance trend visualization (gnuplot)
- 🧮 Comparative analysis vs. theoretical complexities

---

## ⚡ Optimization Techniques

1. **Boyer-Moore**:
   - 🚀 Galil's optimization for linear worst-case
   - 🔄 Two-way matching for small patterns

2. **Horspool's**:
   - 🗜️ Compact bad character representation

3. **General**:
   - 🚄 SIMD for parallel comparisons
   - 💾 Cache-efficient data structures

---

## ⚠️ Known Limitations and Edge Cases

- 📉 Performance drop for very short patterns (< 3 chars)
- 🚫 Potential false positives in HTML attributes
- 💾 Memory constraints for huge files (> 1GB)

---

## 🔮 Future Improvements

1. 🧵 Multi-threading for large file processing
2. 🔍 Approximate string matching capabilities
3. 🖥️ GUI for interaction and visualization
4. 🌐 Unicode and multi-byte character support

---

## 🤝 Contributing

We welcome your contributions! Here's how:

1. 🍴 Fork the repository
2. 🌿 Create a new branch (`git checkout -b feature/AmazingFeature`)
3. 🔧 Make your changes
4. 🔍 Ensure comprehensive testing
5. 📝 Commit your changes (`git commit -m 'Add some AmazingFeature'`)
6. 📤 Push to the branch (`git push origin feature/AmazingFeature`)
7. 🔃 Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<p align="center">
  Made with ❤️
  <br>
  🌟 Star us on GitHub — it helps!
</p>

![Footer](https://via.placeholder.com/800x100.png?text=Thank+You+for+Exploring+Our+Project!)
