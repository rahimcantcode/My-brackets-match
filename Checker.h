#ifndef Checker_H
#define Checker_H

#include "DSStack_array.h"
#include "DSList.h"
#include <fstream>
#include <iostream>

// The Checker class is used to check the balance of brackets in a given file.
class Checker {
private:
    int lineNumber;      // Track the current line number in the file
    bool isReading;      // Flag to indicate if we are currently reading a valid code segment
    bool inBlockComment; // Flag to indicate if currently inside a block comment

public:
    // Constructor initializes the flags and line number
    Checker() : lineNumber(0), isReading(true), inBlockComment(false) {}

    // Checks the balance of brackets in a file using a stack array
    int checkWithArray(const char* inputFile) {
        DSStack_array<char> bracketsStack; // Stack to hold opening brackets for matching
        std::ifstream fileStream(inputFile); // File stream for reading the input file
        
        // Check if the file was successfully opened
        if (!fileStream.is_open()) {
            std::cout << "Could not open file " << inputFile << "\n";
            return -1;
        }

        std::cout << inputFile << ": ";

        // Resetting flags and line counter before reading the file
        lineNumber = 0;
        isReading = true;
        inBlockComment = false;
        
        // Read the file line by line
        while (!fileStream.eof()) {
            lineNumber++;
            char line[500];
            fileStream.getline(line, 500);

            // Process each character in the line
            int index = 0;
            while (line[index] != '\0') {
                // Skip the rest of the line if a line comment is found
                if (line[index] == '/' && line[index + 1] == '/')
                    break;

                // Handle block comments
                if (line[index] == '/' && line[index + 1] == '*') 
                    inBlockComment = true;
                if (line[index] == '*' && line[index + 1] == '/')
                    inBlockComment = false;

                // Toggle reading flag when entering/exiting quotes or char literals
                if (!inBlockComment && (line[index] == '"' || line[index] == '\'') && line[index - 1] != '\\') {
                    isReading = !isReading;
                }

                // Only process brackets if not in a comment or string/char literal
                if (!inBlockComment && isReading) {
                    // Push opening brackets onto the stack
                    if (line[index] == '{' || line[index] == '(' || line[index] == '[') {
                        bracketsStack.push(line[index]);
                    }

                    // Pop from the stack on closing brackets and check for mismatches
                    if (line[index] == '}' && (bracketsStack.isEmpty() || bracketsStack.pop() != '{')) {
                        std::cout << "Bracket mismatch detected for { in line " << lineNumber << '\n';
                        return 1;
                    } else if (line[index] == ')' && (bracketsStack.isEmpty() || bracketsStack.pop() != '(')) {
                        std::cout << "Bracket mismatch detected for ( in line " << lineNumber << '\n';
                        return 1;
                    } else if (line[index] == ']' && (bracketsStack.isEmpty() || bracketsStack.pop() != '[')) {
                        std::cout << "Bracket mismatch detected for [ in line " << lineNumber << '\n';
                        return 1;
                    }
                }

                index++;
            }
        }

        // Check if there are any unmatched opening brackets left in the stack
        if (!bracketsStack.isEmpty()) {
            char remainingBracket = bracketsStack.pop();
            std::cout << "Bracket mismatch detected for " << remainingBracket << " in line " << lineNumber << '\n';
            return 1;
        }

        // If all brackets are matched correctly, the file is OK
        std::cout << "OK \n";
        fileStream.close();
        return 0;
    }

    // Similar to checkWithArray but uses a linked list to manage the brackets
    int checkWithList(const char* inputFile) {
        DSList<char> bracketsList;
        std::ifstream fileStream(inputFile);
        
        if (!fileStream.is_open()) {
            std::cout << "Could not open file " << inputFile << "\n";
            return -1;
        }

        std::cout << inputFile << ": ";

        lineNumber = 0;
        isReading = true;
        inBlockComment = false;
        
        while (!fileStream.eof()) {
            lineNumber++;
            char line[500];
            fileStream.getline(line, 500);

            int index = 0;
            while (line[index] != '\0') {
                if (line[index] == '/' && line[index + 1] == '/')
                    break;

                if (line[index] == '/' && line[index + 1] == '*') 
                    inBlockComment = true;
                if (line[index - 1] != '/' && line[index] == '*' && line[index + 1] == '/')
                    inBlockComment = false;

                if (!inBlockComment && (line[index] == '"' || line[index] == '\'') && line[index - 1] != '\\') {
                    isReading = !isReading;
                }

                if (!inBlockComment && isReading) {
                    if (line[index] == '{' || line[index] == '(' || line[index] == '[') {
                        bracketsList.push_front(line[index]);
                    }

                    if (line[index] == '}' && (bracketsList.isEmpty() || bracketsList.pop_front() != '{')) {
                        std::cout << "Bracket mismatch detected for { in line " << lineNumber << '\n';
                        return 1;
                    } else if (line[index] == ')' && (bracketsList.isEmpty() || bracketsList.pop_front() != '(')) {
                        std::cout << "Bracket mismatch detected for ( in line " << lineNumber << '\n';
                        return 1;
                    } else if (line[index] == ']' && (bracketsList.isEmpty() || bracketsList.pop_front() != '[')) {
                        std::cout << "Bracket mismatch detected for [ in line " << lineNumber << '\n';
                        return 1;
                    }
                }

                index++;
            }
        }

        if (!bracketsList.isEmpty()) {
            char remainingBracket = bracketsList.pop_front();
            std::cout << "Bracket mismatch detected for " << remainingBracket << " in line " << lineNumber << '\n';
            return 1;
        }

        std::cout << "OK \n";
        fileStream.close();
        return 0;
    }
};

#endif // Checker_H
