#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Assignment1.h"

void returnArray()
{
	cout << "No, as C++ does not feature automatic memory management, "
		"and therefore arrays must be passed as pointer references\n";
}


void fillMatrix(int &matrix[rows][cols])
{
	srand(time(NULL));
	for (int x=0; x<rows; x++)
	{
		for (int y=0; y<cols; y++)
		{
			matrix[x][y]=rand() % 10 + 1;
		}
	}
}

void printMatrix(int matrix[rows][cols])
{
	for (int y=0; y<cols; y++)
	{
		for (int x=0; x<rows; x++)
		{
			cout << matrix[rows][cols];
		}
		cout << "\n";
	}
}

void transposeMatrix(int &matrix[rows][cols])
{
	int temp
	for (int x=1; x<rows; x++)
	{
		for (int y=0; y<x; y++)
		{
			temp = matrix[x][y];
			matrix[x][y] = matrix[y][x];
			matrix[y][x] = temp;
		}
	}
}

void iterMatrixProduct(int matA[rows][cols], int matB[rows][cols], int &matProd[rows][cols])
{
	for (int x=0; x<rows; x++)
	{
		for(int y=0; y<cols; y++)
		{
			matProd[x][y] = 0;
			
			for (int i=0; i<rows; i++)
			{
				matProd[x][y] += matA[i][y]*matB[x][i];
			}
		}
	}
}

void recurMatrixProduct(int matA[rows][cols], int matB[rows][cols], int &matProd[rows][cols])
{
	static int x = 0, y = 0, i = 0;
	
	if (x >= rows) {
		return;
	}
	if (y < cols) {
		if (i = cols) {
			matProd[x][y] = matA[i][y]*matB[x][i];
			i++;
			recurMatrixProduct(matA, matB, matProd);
		}
		else if (i < cols) {
			matProd[x][y] += matA[i][y]*matB[x][i];
			i++;
			recurMatrixProduct(matA, matB, matProd);
		}
		i = 0;
		y++;
		recurMatrixProduct(matA, matB, matProd);
	}
	y = 0;
	x++;
	recurMatrixProduct(matA, matB, matProd);
}

void fillMatrixPtr(int **matPtr)
{
	srand(time(NULL));
	for (int x=0; x<rows; x++)
	{
		for (int y=0; y<cols; y++)
		{
			*(matPtr+x)+y=rand() % 10 + 1;
		}
	}
}

void printMatrixPtr(int **matPtr)
{
	for (int y=0; y<cols; y++)
	{
		for (int x=0; x<rows; x++)
		{
			cout << *(matPtr+x)+y;
		}
		cout << "\n";
	}
}

void transposeMatrixPtr(int **matPtr)
{
	int temp
	for (int x=1; x<rows; x++)
	{
		for (int y=0; y<x; y++)
		{
			temp = *(matrix+x)+y;
			*(matrix+x)+y = *(matrix+y)+x;
			*(matrix+y)+x = temp;
		}
	}
}

void fillMatrix1d(int &matrix[rows], int cols)
{
	srand(time(NULL));
	for (int x=0; x<rows; x++)
	{
		for (int y=0; y<cols; y++)
		{
			matrix[x+(y*cols)]=rand() % 10 + 1;
		}
	}
}

void printMatrix1d(int matrix[rows], int cols)
{
	for (int y=0; y<cols; y++)
	{
		for (int x=0; x<rows; x++)
		{
			cout << matrix[rows+(y*cols)];
		}
		cout << "\n";
	}
}
