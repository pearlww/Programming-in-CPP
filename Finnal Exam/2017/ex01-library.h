#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

#include <vector>
#include <string>

using namespace std;

//Exercise 1 (a) Check and correct if necessary
/*
 * Create an n x m matrix.
 */
int ** createMatrix(unsigned int n, unsigned int m);

//Exercise 1 (b) Implement this function
/*
 * Create a copy the matrix A;
 */
int ** duplicateMatrix(int ** A, unsigned int n, unsigned int m);

//Exercise 1 (c) Implement this function
/*
 * Initialize all entries of the matrix to 0
 */
void initMatrix(int ** A, unsigned int n, unsigned int m);

//Exercise 1 (d) Implement this function
/*
 * Deallocate all memory allocated to the matrix.
 */
void deallocateMatrix(int ** A, unsigned int n);

//Exercise 1 (e) Implement this function
/*
 * Make the picture bi-tonal: each pixel can be either black (0) or white (255).
 * This function should scan all elements of A, and replace all values
 * 		below the given threshold with value 0;
 * 		equal or above the given threshold with value 255;
 * Hence, this filter sets to white all grey entries clearer than the given threshold, and to black all the ones darker than the given threshold
 * Notes:
 * 	The function has to apply the filter on a copy, let's say B, of A. Such modified copy B has to be returned.
 * 	The function must not modify A.
 */
int ** makeBitonal(int ** A, unsigned int n, unsigned int m, int threshold);

//Do not modify
/*
 * Pretty print of the matrix
 */
void printMatrix(int ** A, unsigned int n, unsigned int m, string description);

#endif /* EX01_LIBRARY_H_ */
