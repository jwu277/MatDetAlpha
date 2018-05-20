/*
 * Author: James Wu
 * Date: 24 January 2018
 * Purpose: To create a recursive algorithm to calculate the determinant
 *          for an arbitrarily-sized square matrix
 */

#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define N 4 // number of rows in square matrix

/* Prototypes */
double det(double A[N * N], int m);
void generateChild(double A[N * N], double C[N * N], int m, int i);
void printMatrix(double A[], int m);

int main(void) {

	double A[N * N] = {1.1, 2.2, 3.3, 4.4, 4.2, 3.4, 2.202, 1.1, 4.3, 3.4, 2.5, 1.7, 1.6, 2.5, 3.4, 4.1};

	double result = det(A, N);

	printf("Square matrix:\n\n");
	printMatrix(A, N);
	printf("\n");

	printf("Result: %.3f\n", result);
	printf("\n");

	system("PAUSE");
	return 0;

}

/*
 * Calculates the determinant of a square matrix
 * Parameters: A (double[]) - matrix whose determinant is to be calculated
 *             m (int)      - the number of rows "supposed" to be in matrix
 * Return (double): the determinant of A
 */
double det(double A[N * N], int m) {

	double sum = 0;
	int sign = 1;
	double child[N * N];

	/* Loop through top row */
	for (int i = 0; i < m; i++) {

		generateChild(A, child, m, i);
		sum += sign * A[i] * det(child, m - 1); // recursive step
		sign *= -1;

	}

	/* Base case */
	if (m == 0) {
		sum = 1;
	}

	return sum;

}

/*
 * Creates a child matrix for a specific column
 * Parameters: A (double[N * N]) - the parent matrix
 *             C (double[N * N]) - the target child matrix
 *             m (int)           - # of rows "supposed" to be in C
 *             i (int)           - column to exclude
 */
void generateChild(double A[N * N], double C[N * N], int m, int i) {

	int k = 0; // counter for child matrix

	/* j is the counter for parent matrix */
	for (int j = m; j < m * m; j++) {
		if (j % m != i) {
			C[k] = A[j];
			k++;
		}
	}

}

/*
 * Prints a 1D array as a 2D square matrix
 * Parameters: A (double []) - matrix to print
 *             m (int)       - number of rows in matrix A
 */
void printMatrix(double A[], int m) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%8.3f ", A[i*m + j]);
		}
		printf("\n");
	}

}