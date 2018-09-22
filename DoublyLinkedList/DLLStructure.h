#pragma once
#ifndef DLLSTRUCTURE_H
#define DLLSTRUCTURE_H

#include "Node.h"
//Doubly Linked List Class
class DLLStructure
{
public:
	//declaring constructor methods
	DLLStructure();
	DLLStructure(int array[], int size);
	//declaring class methods
	void PrintDLL();
	void Reverse();
	void InsertAfter(int valueToInsertAfter, int valueToBeInserted);
	void InsertBefore(int valueToInsertBefore, int valueToBeInserted);
	void Delete(int value);
	void Sort();
	bool IsEmpty();
	int GetHead();
	int GetTail();
	int GetSize();
	int GetMax();
	int GetMin();
	//copy constructor method
	DLLStructure(DLLStructure& dlls);
	//destructor method
	~DLLStructure();

private:
	//declaring object variables
	Node* first;
	Node* last;
	int size;
};

#endif