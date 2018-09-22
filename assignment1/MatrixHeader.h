#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

void returnArray();

void fillMatrix(int &matrix[rows][cols]);

void printMatrix(int matrix[rows][cols]);

void transposeMatrix(int &matrix[rows][cols]);

void iterMatrixProduct(int matA[rows][cols], int matB[rows][cols], int &matProd[rows][cols]);

void recurMatrixProduct(int matA[rows][cols], int matB[rows][cols], int &matProd[rows][cols]);

void fillMatrixPtr(int **matPtr);

void printMatrixPtr(int **matPtr);

void transposeMatrixPtr(int **matPtr);

void fillMatrix1d(int &matrix[rows], int cols);

void printMatrix1d(int matrix[rows], int cols);

#endif
