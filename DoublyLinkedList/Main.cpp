#include <iostream>
#include "Node.h"
#include "DLLStructure.h"

int main()
{
	int array[5] = { 11, 2, 7, 22, 4 };

	DLLStructure dll(array, 5); // note that 5 is the size of the array
	dll.InsertAfter(7, 13); // To insert 13 after the first occurence of 7
	dll.InsertBefore(7, 26); // To insert 26 before the first occurence of 7
	dll.PrintDLL(); // the output should be: 11, 2, 26, 7, 13, 22, 4

	dll.Delete(22);
	dll.PrintDLL(); // the output should be: 11, 2, 26, 7, 13, 4

	dll.Sort();
	dll.PrintDLL();

	DLLStructure dll2(dll);
	dll2.PrintDLL();

	return 0;
}