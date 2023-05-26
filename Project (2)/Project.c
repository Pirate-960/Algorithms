#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 256
// Function prototypes--------------------------------------------------------------------//
int max(int a, int b);
char *read_file(const char *filename);
void save_file(const char *filename, const char *content);
void addList(const char *filename, const char *pattern, const int bad_char[MAX_CHAR], int good[], int patternLen);
void insert_mark_tag(const char *outputS, const char *text, const char *pattern, int *count);
int brute_force(const char *text, const char *pattern, int *comparisons);
void shift_Table(char *pattern, int PatternLength, int ShiftTable[MAX_CHAR]);
int Horspool_Search(char *text, int TextLength, char *pattern, int PatternLength, int *comparisons);
void Horspool_Algorithm(char *text, char *pattern);
void preprocess_bad_character(const char *pattern, int pattern_len, int bad_char[MAX_CHAR]);
void preprocess_good_suffix(const char *pattern, int pattern_len, int good_suffix[]);
int boyer_moore(const char *text, const char *pattern, int *comparisons);
void print_bad_symbol_table(const int bad_char[MAX_CHAR]);
void print_good_suffix_table(const int good_suffix[], int pattern_len);
//----------------------------------------------------------------------------------------//
// Function to find the maximum of two integers
int max(int a, int b) {
    return a > b ? a : b;  // Returns 'a' if 'a' is greater than 'b', otherwise returns 'b'
}
//----------------------------------------------------------------------------------------//
// Utility function to read the contents of a file into a string
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");  // Opens the file in binary mode for reading
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);  // Prints an error message if the file cannot be opened
        exit(EXIT_FAILURE);  // Exits the program with a failure status
    }

    fseek(file, 0, SEEK_END);  // Moves the file pointer to the end of the file
    long length = ftell(file);  // Retrieves the current position of the file pointer, which represents the file size
    if (length < 26) {
        printf("Error: Invalid pattern");  // Prints an error message if the file size is less than 26
        exit(EXIT_FAILURE);  // Exits the program with a failure status
    }
    fseek(file, 0, SEEK_SET);  // Moves the file pointer back to the beginning of the file

    char *content = (char *)malloc(length - 25);  // Allocates memory to store the file content, excluding the last 25 characters
    if (content == NULL) {
        printf("Error allocating memory for file content.\n");  // Prints an error message if memory allocation fails
        exit(EXIT_FAILURE);  // Exits the program with a failure status
    }
    int i = 0;
    int j = 0; 
    length -= 14;  // Decreases the file size by 14
    for (; i < 12; i++) {
        fgetc(file);  // Reads and discards the next character from the file, 12 times
    }
    for (; i < length; i++, j++) {
        content[j] = fgetc(file);  // Reads the next character from the file and stores it in the 'content' array
    }
    fclose(file);  // Closes the file
    content[j] = '\0';  // Appends a null terminator at the end of the 'content' array to signify the end of the string
    
    return content;  // Returns the pointer to the dynamically allocated 'content' array
}
//----------------------------------------------------------------------------------------//
// Utility function to save the highlighted HTML file
void save_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");  // Opens the file in append mode
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);  // Prints an error message if the file cannot be opened
        exit(EXIT_FAILURE);  // Exits the program with a failure status
    }

    fwrite(content, 1, strlen(content), file);  // Writes the content to the file
    fclose(file);  // Closes the file
}
//----------------------------------------------------------------------------------------//
// addList -> generates an HTML file containing tables for a "Bad Symbol Table" and a "Good Symbol Table," along with some additional HTML code
void addList(const char *filename, const char *pattern, const int bad_char[MAX_CHAR], int good[], int patternLen) {
    int i, j;
    FILE *output = fopen(filename, "w");  // Opens the file in write mode
    fprintf(output, "<html>\n<head>\n<style>\ntable, th, td {\nborder: 1px solid black;\ntext-align: center;\n}\nbody {\n\tword-wrap: break-word;\n}\n</style>\n</head>\n<body>\n<h2>Bad Symbol Table</h2>\n<table style>\n\t<tr>\n\t\t<th>*</th>\n");

    // Printing the Bad Symbol Table
    for (i = 1; i < MAX_CHAR; i++) {
        if (bad_char[i] != -1)
            fprintf(output, "\t\t<th>%c</th>\n", i);  // Prints a table header for each character that has a valid value (-1 represents an invalid value)
    }
    fprintf(output, "\t</tr>\n\t<tr>\n\t\t<td>%d</td>\n", patternLen);  // Prints the number of characters in the pattern in a table cell
    for (i = 1; i < MAX_CHAR; i++) {
        if (bad_char[i] != -1)
            fprintf(output, "\t\t<td>%d</td>\n", bad_char[i]);  // Prints the corresponding values from the 'bad_char' array in table cells
    }
    fprintf(output, "\t</tr>\n</table>\n<h2>Good Symbol Table</h2>\n<table style>\n\t<tr>\n\t\t<th>k</th>\n\t\t<th>Pattern</th>\n\t\t<th>Shift</th>\n</tr>\n");

    // Printing the Good Symbol Table
    for (i = 0; i < patternLen; i++) {
        fprintf(output, "<tr>\n\t\t<td>%d</td>\n\t\t<td>", i + 1);  // Prints the row number in a table cell

        for (j = 0; j < patternLen; j++) {
            if (patternLen - i - 1 == j) {
                fprintf(output, "<u>");  // Adds an underline tag for the current character in the pattern
            }
            fprintf(output, "%c", pattern[j]);  // Prints the characters of the pattern
        }
        fprintf(output, "</u>");
        
        fprintf(output, "</td>\n\t\t<td>%d</td>\n</tr>\n", good[i]);  // Prints the corresponding shift value in the Good Symbol Table
    }
    fprintf(output, "\t</tr>\n");
    fprintf(output, "\t</tr>\n</table>\n\n</body>\n</html>\n\n<h2>Output</h2>\n");  // Prints HTML code for other sections of the file
    fclose(output);  // Closes the file
}
//----------------------------------------------------------------------------------------//
// Utility function to print a portion of a string to a file
void printOutputNStr(FILE *output, const char *str, const int num) {
    int i;

    // Iterate over the characters in the string up to the specified number
    for (i = 0; i < num; i++) {
        // Write each character to the output file
        fputc(str[i], output);
    }

    return;
}
//----------------------------------------------------------------------------------------//
// Utility function to insert <mark></mark> tag around the pattern
void insert_mark_tag(const char *outPutS, const char *text, const char *pattern, int *count) {
    const char *mark_open = "<mark>";
    const char *mark_close = "</mark>";
    FILE *output = fopen(outPutS,"a");
    size_t text_len = strlen(text);
    size_t pattern_len = strlen(pattern);
    size_t mark_open_len = strlen(mark_open);
    size_t mark_close_len = strlen(mark_close);

    // Calculate the required memory for the highlighted text

    // Set the starting position for writing the highlighted text, accounting for additional characters

    const char *src = text;

    int idx = 0;
    int temp;
    int lastIndexE = -1;
    int lastIndexS = 0;

    // Iterate over the source text
    while (src < text + text_len) {
        // Check if the current portion of the source matches the pattern
        if (strncmp(src, pattern, pattern_len) == 0) {
            // Insert the opening <mark> tag
            fprintf(output,mark_open);

            // Copy the text between the last match and the current match
            if (idx >= lastIndexE) {
                printOutputNStr(output, src, pattern_len);
            } else {
                temp = lastIndexE - idx;
                printOutputNStr(output, src + temp, idx - lastIndexS);
            }

            // Insert the closing </mark> tag
            fprintf(output, mark_close);

            // Update the indices of the last match positions
            lastIndexE = idx + pattern_len;
            lastIndexS = idx;
        } else {
            // Copy non-matching characters
            if (idx >= lastIndexE) {
                fputc(*src, output);
            }
        }
        // Move to the next character
        *src++;
        idx++;
    }

    // Append the closing </p> tag
    fprintf(output,"</p>\0");

    return;
}
//----------------------------------------------------------------------------------------//
// Brute-force string matching
int brute_force(const char *text, const char *pattern, int *comparisons) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int count = 0;

    // Iterate over the text using a sliding window approach
    for (int i = 0; i <= text_len - pattern_len; i++) {
        int j;

        // Compare characters of the pattern with the corresponding characters in the text
        for (j = 0; j < pattern_len; j++) {
            (*comparisons)++;  // Increment the comparison counter

            // If a mismatch is found, break out of the inner loop
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the inner loop completed without a break, a match is found
        if (j == pattern_len) {
            count++;  // Increment the match counter
        }
    }

    // Return the total number of matches found
    return count;
}
//----------------------------------------------------------------------------------------//
// Horspool's algorithm
//----------------------------------------------------------------------------------------//
// Print the Bad Symbol Table
void print_shift_table(const int ShiftTable[MAX_CHAR]) {
    printf("Shift Table:\n");  // Print a header indicating the name of the table
    for (int i = 1; i < MAX_CHAR; i++) {
        if (ShiftTable[i] != -1) {
            printf("%c: %d\n", (char)i, ShiftTable[i]);  // Print the character and its corresponding distance
        }
    }
    printf("\n");  // Print a blank line for readability
}
//----------------------------------------------------------------------------------------//
// Function to generate the shift table for Horspool's algorithm
void shift_Table(char *pattern, int PatternLength, int ShiftTable[MAX_CHAR]) {
    // Initialize the shift table array with -1
    for (int i = 0; i < MAX_CHAR; i++) {
        ShiftTable[i] = -1;
    }
    // Compute the shift table
    for (int i = 0; i < PatternLength - 1; i++) {
        ShiftTable[(int)pattern[i]] = PatternLength - i - 1;
    }

    print_shift_table(ShiftTable);
}
//----------------------------------------------------------------------------------------//
// Horspool's algorithm for string matching
int Horspool_Search(char *text, int TextLength, char *pattern, int PatternLength, int *comparisons) {
    int ShiftTable[MAX_CHAR];
    shift_Table(pattern, PatternLength, ShiftTable);  // Generate the shift table
    int j;  // Loop counter
    int shift;
    int count = 0;
    int i = 0;

    // Main loop to search for the pattern in the text
    while (i <= TextLength - PatternLength) {
        int j = PatternLength - 1;

        // Compare characters from right to left until a mismatch is found or the pattern is fully matched
        while (j >= 0 && ++(*comparisons) && (pattern[j] == text[i + j])) {
            j--;
        }
        //Shifting
        shift = ShiftTable[(int)text[i + PatternLength - 1]];
        i += shift > 0 ? shift : PatternLength;

        //Full match occurs
        if (j < 0) {
            count++;  // Increment the match counter
        } 
    }

    return count;  // Return the total number of matches found
}
//----------------------------------------------------------------------------------------//
// Horspool's algorithm for string matching
void Horspool_Algorithm(char *text, char *pattern) {
    int count = 0;
    int TextLength = strlen(text);
    int PatternLength = strlen(pattern);
    int comparisons = 0;

    // Start measuring execution time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Perform Horspool's algorithm to find matches
    count = Horspool_Search(text, TextLength, pattern, PatternLength, &comparisons);

    // Stop measuring execution time
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate the execution time in milliseconds
    double execution_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0; // seconds to milliseconds
    execution_time += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0; // nanoseconds to milliseconds

    
    // Print the results
    printf("Occurrences: %d\n", count);
    printf("Comparisons: %d\n", comparisons);
    printf("Running time: %.4f ms\n", execution_time);
}
//----------------------------------------------------------------------------------------//
// Boyer-Moore algorithm
// preprocess_bad_character -> generate bad character table
void preprocess_bad_character(const char *pattern, int pattern_len, int bad_char[MAX_CHAR]) {
    // Initialize the bad character array with -1
    for (int i = 0; i < MAX_CHAR; i++) {
        bad_char[i] = -1;
    }

    // Compute the bad character table
    for (int i = 0; i < pattern_len - 1; i++) {
        bad_char[pattern[i]] = pattern_len - i - 1;
    }
}
//----------------------------------------------------------------------------------------//
// preprocess_good_suffix -> generate good suffix table
void preprocess_good_suffix(const char *pattern, int pattern_len, int good_suffix[]) {
    int i, j, k, l, m;

    // Initialize the good suffix table with default values
    for(i = 0; i < pattern_len - 1; i++){
        good_suffix[i] = pattern_len - 1;
    }
    good_suffix[pattern_len - 1] = pattern_len;

    // Calculate the values for the good suffix table
    for(int i = pattern_len - 1, l = 0; i > 0; i--, l++){
        for(k = pattern_len - 2; k >= 0; k--){
            // Check if the pattern[k - l - 1] matches the pattern[i - 1]
            if(k - l - 1 >= 0 && pattern[k - l - 1] == pattern[i - 1])
                continue;

            // Compare the characters in the suffix and the pattern
            for(j = k, m = 0; j >= k - l && j >= 0; j--, m++){
                if(pattern[j] != pattern[pattern_len - m - 1])
                    break;
            }

            // If the suffix matches the pattern, update the good suffix value
            if(j < k - l || j < 0){
                good_suffix[l] = pattern_len - k - 1;
                break;
            }
        }
    }

    // Handle the special case where the pattern ends with a good suffix
    k = 0;
    for(i = pattern_len - 1; i > 0; i--, k++){
        // Compare the characters in the prefix and the pattern
        for(j = 0; j <= k; j++){
            if(pattern[j] != pattern[i + j])
                break;
        }

        // If the prefix matches the pattern, update the good suffix value
        if(j > k){
            good_suffix[pattern_len - 1] = i;
        }
    }
}
//----------------------------------------------------------------------------------------//
// boyer_moore Algorithm
int boyer_moore(const char *text, const char *pattern, int *comparisons) {
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int bad_char[MAX_CHAR];
    int good_suffix[pattern_len];
    int count = 0;

    // Preprocess the bad character and good suffix tables
    preprocess_bad_character(pattern, pattern_len, bad_char);
    preprocess_good_suffix(pattern, pattern_len, good_suffix);

    int i, j, k, shift;
    for (i = pattern_len - 1; i < text_len; i += shift) {
        // Compare the pattern with the text from right to left
        for (j = i, k = 0; k < pattern_len; k++, j--) {
            ++(*comparisons);
            if (text[j] != pattern[pattern_len - k - 1]) {
                break;
            }
        }
        
        if (k == pattern_len) {
            // The pattern is found
            count++;
            shift = 1;
        } else if (k == 0) {
            // Mismatch at the first character of the pattern
            shift = bad_char[text[j]];
            if (shift == -1)
                shift = pattern_len;
        } else {
            // Mismatch at a character within the pattern
            shift = max(good_suffix[k - 1], max(1, bad_char[text[i]] - k + 1));
        }
    }

    return count;
}
//----------------------------------------------------------------------------------------//
// Print the Bad Symbol Table
void print_bad_symbol_table(const int bad_char[MAX_CHAR]) {
    printf("Bad Symbol Table:\n");  // Print a header indicating the name of the table
    for (int i = 1; i < MAX_CHAR; i++) {
        if (bad_char[i] != -1) {
            printf("%c: %d\n", (char)i, bad_char[i]);  // Print the character and its corresponding distance
        }
    }
    printf("\n");  // Print a blank line for readability
}
//----------------------------------------------------------------------------------------//
// Print the Good Suffix Table
void print_good_suffix_table(const int good_suffix[], int pattern_len) {
    printf("Good Suffix Table:\n");  // Print a header indicating the name of the table
    int j = 1;
    for (int i = pattern_len - 1; i >= 0; i--) {
        printf("%d: %d\n", j, good_suffix[j - 1]);  // Print the index and its corresponding length
        j++;
    }
    printf("\n");  // Print a blank line for readability
}
//----------------------------------------------------------------------------------------//
// Main Function -> Execution starts here!
int main(int argc, char *argv[]) {
    /* Command line argument check
    if (argc != 3) {
        printf("Usage: %s <html_filename> <pattern>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    */

    struct timespec start_time, end_time;
      char html_filename[100];
    printf("Html file name (example.html):");
    scanf("%s", html_filename);

    char pattern[1000];
    printf("Pattern: ");
    scanf("%s", pattern);

    char *text = read_file(html_filename);  // Read the contents of the HTML file into a character array
    int comparisons;
    int bad_char[MAX_CHAR];
    int good_suffix[strlen(pattern)];

    // Brute-force Algorithm---------------------------------------------------------------//

    comparisons = 0;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    int brute_force_count = brute_force(text, pattern, &comparisons);  // Call the brute force algorithm function
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double execution_time_brute = (end_time.tv_sec - start_time.tv_sec) * 1000.0;  // Convert the time to milliseconds
    execution_time_brute += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    printf("***-------------------------------------------------------------------------------------------***\n");
    printf("Brute-force Algorithm:\nOccurrences: %d\nComparisons: %d\nRunning time: %.4f ms\n", brute_force_count, comparisons, execution_time_brute);
    printf("***-------------------------------------------------------------------------------------------***\n");

    // Horspool's Algorithm-----------------------------------------------------------------//

    comparisons = 0;
    printf("***-------------------------------------------------------------------------------------------***\n");
    printf("Horspool Algorithm:\n");
    preprocess_bad_character(pattern, strlen(pattern), bad_char);  // Preprocess the bad character table
    //print_bad_symbol_table(bad_char);  // Print the bad symbol table
    Horspool_Algorithm(text, pattern);  // Call the Horspool's algorithm function
    printf("***-------------------------------------------------------------------------------------------***\n");

    // Boyer-Moore Algorithm----------------------------------------------------------------//

    printf("***-------------------------------------------------------------------------------------------***\n");
    printf("Boyer-Moore Algorithm:\n");

    preprocess_bad_character(pattern, strlen(pattern), bad_char);  // Preprocess the bad character table
    preprocess_good_suffix(pattern, strlen(pattern), good_suffix);  // Preprocess the good suffix table

    print_bad_symbol_table(bad_char);  // Print the bad symbol table
    print_good_suffix_table(good_suffix, strlen(pattern));  // Print the good suffix table

    comparisons = 0;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    int boyer_moore_count = boyer_moore(text, pattern, &comparisons);  // Call the Boyer-Moore algorithm function
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double execution_time_boyer_moore = (end_time.tv_sec - start_time.tv_sec) * 1000.0;  // Convert the time to milliseconds
    execution_time_boyer_moore += (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    printf("Occurrences: %d\nComparisons: %d\nRunning time: %.4f ms\n\n", boyer_moore_count, comparisons, execution_time_boyer_moore);
    printf("***-------------------------------------------------------------------------------------------***\n");

    // Highlight occurrences in the text and save the output
    addList("output.html", pattern, bad_char, good_suffix, strlen(pattern));  // Create an HTML file with tables for the bad symbol table and good symbol table
    insert_mark_tag("output.html",text, pattern, &brute_force_count);  // Insert HTML mark tags to highlight occurrences of the pattern in the text
 

    //free(highlighted);
    free(text);

    return 0;
}
//----------------------------------------------------------------------------------------//
