# MatDetAlpha
Recursive matrix determinant calculator.

Due to limitations with 2D arrays in C, MatDetAlpha uses a 1D array with N^2 entries.
The size of the square matrix and its entries are to be specified within the code.
The 1D array is of the format \[Row, 1, entries, Row, 2, entries, ...\].

The computational time is approximately O(n!) as dictated by the algorithm's recursive nature.
