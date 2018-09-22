#include <iostream>
#include "Assigment1.h"

const int rows = 5;
const int cols = 5;

int main()
{
	using std::cout;
	using std::endl;

	cout << "Question 1" << endl;
	returnArray()
	
	int myMatrix[rows][cols];
	
	fillMatrix(&myMatrix)
	
	cout << "Question 2 + 3" << endl;
	printMatrix(myMatrix)
	
	cout << "Question 4" << endl;
	transposeMatrix(&myMatrix)
	
	printMatrix(myMatrix)
	
	int A[rows][cols];
	int B[rows][cols];
	
	fillMatrix(&A)
	fillMatrix(&B)
	int C[rows][cols];
	
	cout << "Question 5" << endl;
	iterMatrixProduct(A, B, &C)
	
	printMatrix(C)
	
	cout << "Question 6" << endl;
	recurMatrixProduct(A, B, &C)
	
	printMatrix(C)
	
	int **myMatrixPtr;
	myMatrixPtr = new int*[rows];
	for (int i = 0; i < cols; i++)
	{
		myMatrixPtr[i] = new int[rows];
	}
	
	cout << "Question 7" << endl;
	fillMatrixPtr(myMatrixPtr)
	
	printMatrixPtr(myMatrixPtr)
	
	transposeMatrixPtr(myMatrixPtr)
	
	printMatrixPtr(myMatrixPtr)
	
	cout << "Question 8" << endl;
	fillMatrix(&myMatrix)
	
	printMatrix(myMatrix)
	
	transposeMatrix(&myMatrix)
	
	printMatrix(myMatrix)
	
	return 0;
}
