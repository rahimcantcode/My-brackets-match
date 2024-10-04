# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Abderrahim Latreche

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[x] Early submission (48 hrs)

[x] Bonus work. Describe: managed comments, strings, and chars when searching for bracket errors

Place [x] for what applies.


## Answers
1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   > The list-based implementation took approximately 2125 microseconds to check all three files, while the array-based implementation took around 2203 microseconds. Both implementations have a Big-O notation of O(n*m), where n is the number of lines in the code and m is the number of characters in each line.

2. Discuss the difference in memory usage based on **your** implementation.

   > The list implementation used 455,454 bytes, while the array implementation used 472,752 bytes. The array implementation allocates memory for a fixed size array, leading to higher memory usage, whereas the list implementation dynamically allocates memory as needed.

3. Which version would you use in practice. Why?

   > In practice, I would use the list implementation due to its more efficient memory usage and slightly faster runtime compared to the array implementation.

4. Make sure that your stack implementations does not have memory leaks.

   ```
    For DSStack_array:
   ===============================================================================
   All tests passed (15 assertions in 1 test case)

   ==37648== 
   ==37648== HEAP SUMMARY:
   ==37648==     in use at exit: 0 bytes in 0 blocks
   ==37648==   total heap usage: 2,663 allocs, 2,663 frees, 472,752 bytes allocated
   ==37648== 
   ==37648== All heap blocks were freed -- no leaks are possible
   ==37648== 
   ==37648== For lists of detected and suppressed errors, rerun with: -s
   ==37648== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
   ```


   ```
   For DSStack_list:
   ===============================================================================
   All tests passed (20 assertions in 1 test case)

   ==37892== 
   ==37892== HEAP SUMMARY:
   ==37892==     in use at exit: 0 bytes in 0 blocks
   ==37892==   total heap usage: 2,683 allocs, 2,683 frees, 455,454 bytes allocated
   ==37892== 
   ==37892== All heap blocks were freed -- no leaks are possible
   ==37892== 
   ==37892== For lists of detected and suppressed errors, rerun with: -s
   ==37892== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
   ``` 

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   > Yes, I attempted the first bonus by ensuring that the bracket checker does not consider comments, strings, or chars when checking for bracket errors. This was achieved by adding logic to ignore content within comments and string literals.
