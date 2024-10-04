#include <iostream>
#include <chrono>
#include "Checker.h"  // Include the Checker class

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    Checker checker;  // Instantiate a Checker object
    int result = 0;

    // Start timing the bracket checking process using the array-based stack
    auto start = high_resolution_clock::now();

    // Loop through all provided file names to check each one
    for (int i = 1; i < argc; ++i) {
        // Using the checkWithArray method to validate brackets in each file
        if (checker.checkWithArray(argv[i]) == 1) {
            result = 1;  // Set result to 1 if any file has a bracket mismatch
        }
    }

    // Stop timing and calculate the duration
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    // Output the duration of the process
    cout << "Checking all files took " << duration.count() << " microseconds with array-based stack\n";

    // A return code != 0 indicates that there was a mismatch in at least one file
    return result;
}
