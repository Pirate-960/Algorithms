# String Matching Algorithms Comparison

This project implements and compares three string matching algorithms: Brute-force, Horspool's algorithm, and Boyer-Moore algorithm. The comparison is performed on HTML files with both English text and random bit-strings.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Algorithms Implemented](#algorithms-implemented)
3. [File Structure](#file-structure)
4. [How to Compile and Run](#how-to-compile-and-run)
5. [Input Types](#input-types)
6. [Output](#output)
7. [Performance Metrics](#performance-metrics)
8. [Contributing](#contributing)
9. [License](#license)

## Project Overview

This project is an implementation of the Homework 1 assignment for the CSE 2046/2246 Analysis of Algorithms course (Spring 2023). The main objectives are:

1. Implement three string matching algorithms
2. Compare their performance on different types of input
3. Highlight pattern occurrences in HTML files
4. Generate and analyze performance metrics

## Algorithms Implemented

1. **Brute-force string matching**: A simple algorithm that checks for a match at every position in the text.
2. **Horspool's algorithm**: An improvement over the naive approach, using a bad character rule for faster skipping.
3. **Boyer-Moore algorithm**: A more advanced algorithm using both bad character and good suffix rules for efficient pattern matching.

## File Structure

- `main.c`: The main program that implements all three algorithms and performs the comparison.
- `inputCreatorTypeOne.c`: Generates input files of Type 1 (English text HTML).
- `inputCreatorTypeTwo.c`: Generates input files of Type 2 (random bit-string HTML).
- `input1.html`, `input2.html`, `input3.html`: Sample input files of Type 1.
- `bitInput1.html`, `bitInput2.html`, `bitInput3.html`: Sample input files of Type 2.
- `output.html`: The output file with highlighted pattern occurrences.

## How to Compile and Run

1. Compile the main program:
   ```
   gcc -o string_matcher main.c
   ```

2. Run the program:
   ```
   ./string_matcher
   ```

3. Follow the prompts to enter the HTML filename and the pattern to search for.

## Input Types

1. **Type 1**: HTML files with English text
   - Generated from real web pages or long text documents
   - Patterns are meaningful English words

2. **Type 2**: HTML files with random bit-strings
   - Generated using `inputCreatorTypeTwo.c`
   - Patterns are random bit-strings of various lengths

## Output

1. **Highlighted HTML**: The input HTML file with pattern occurrences highlighted using `<mark></mark>` tags.
2. **Console output**:
   - Bad Symbol Table
   - Good Suffix Table
   - Number of occurrences
   - Number of comparisons
   - Running time (in milliseconds)

## Performance Metrics

The program measures and compares the following metrics for each algorithm:

1. Number of character comparisons
2. Running time (in milliseconds)
3. Number of pattern occurrences found

These metrics are printed to the console for easy comparison.

## Contributing

Contributions to improve the algorithms or add new features are welcome. Please follow these steps:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/your-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin feature/your-feature`)
5. Create a new Pull Request

## License

This project is open source and available under the [MIT License](https://opensource.org/licenses/MIT).
