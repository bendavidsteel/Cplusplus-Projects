#include "DLLStructure.h"
#include "Node.h"
#include <iostream>


DLLStructure::DLLStructure()
{
	//default constructor method creating empty list of length 1
	Node* DLList = new Node;
	DLList->setData(NULL);
	this->first = DLList;
	this->last = DLList;
	this->size = 1;
}

DLLStructure::DLLStructure(int array[], int size)
{
	//constructor method copying array into doubly linked list
	//creating pointer to array of pointers to create objects
	Node** DLList = new Node*[size];
	//creating new Node objects for each pointer in array
	for (int i=0; i<size; ++i)
	{
		DLList[i] = new Node;
	}
	//setting DLL variables
	this->first = DLList[0];
	this->last = DLList[size - 1];
	this->size = size;
	//setting variables for each Node of DLL
	DLList[0]->setData(array[0]);
	DLList[0]->setNext(DLList[1]);
	DLList[0]->setPrevious(nullptr);

	for (int i = 1; i<size-1; ++i)
	{
		DLList[i]->setData(array[i]);
		DLList[i]->setNext(DLList[i + 1]);
		DLList[i]->setPrevious(DLList[i - 1]);
	}

	DLList[size-1]->setData(array[size-1]);
	DLList[size-1]->setNext(nullptr);
	DLList[size-1]->setPrevious(DLList[size-2]);
	//deleting pointer to array of pointers
	delete[] DLList;
}

void DLLStructure::PrintDLL()
{
	Node* NodeToPrint = this->first;
	do //looping through all nodes and outputing data
	{
		std::cout << NodeToPrint->getData() << " ";
		NodeToPrint = NodeToPrint->getNext();
	} while (NodeToPrint != nullptr);

	std::cout << '\n';
}

void DLLStructure::InsertAfter(int valueToInsertAfter, int valueToBeInserted)
{ //method to insert number after a certain number
	Node* NodeToCheck = this->first;
	do //looping through all nodes
	{
		if (valueToInsertAfter == NodeToCheck->getData())
		{  //looking for matching values
			Node* NewNode = new Node;
			Node* NextNode;

			NextNode = NodeToCheck->getNext();
			//creating new node and setting object variables
			NewNode->setData(valueToBeInserted);
			NewNode->setNext(NextNode);
			NewNode->setPrevious(NodeToCheck);

			NodeToCheck->setNext(NewNode);
			NextNode->setPrevious(NewNode);

			break;
		}
		NodeToCheck = NodeToCheck->getNext();
	} while (NodeToCheck != nullptr);
}

void DLLStructure::Reverse()
{ //method to reverse the order of the list
	Node *NodePivot = this->first;
	Node *NextNode = NodePivot;

	this->last = NodePivot;

	do
	{ //looping through all nodes and swapping pointers
		NodePivot = NextNode;
		NextNode = NodePivot->getNext();

		NodePivot->setNext(NodePivot->getPrevious());
		NodePivot->setPrevious(NextNode);

	} while (NextNode != nullptr);

	this->first = NodePivot;
}

void DLLStructure::InsertBefore(int valueToInsertBefore, int valueToBeInserted)
{ //method to insert value before another value
	//done by reversing list, running insertafter method, then re-reversing list
	this->Reverse();
	this->InsertAfter(valueToInsertBefore, valueToBeInserted);
	this->Reverse();
}

void DLLStructure::Delete(int value){ //method to delete value from list for given value
	Node* NodeToCheck = this->first;
	do
	{
		if (value == NodeToCheck->getData())
		{ //checking for value
			Node* PrevNode = NodeToCheck->getPrevious();
			Node* NextNode = NodeToCheck->getNext();
			//deleting node then changing pointers around it
			delete PrevNode->getNext();

			PrevNode->setNext(NextNode);
			NextNode->setPrevious(PrevNode);

			break;
		}
		NodeToCheck = NodeToCheck->getNext();
	} while (NodeToCheck != nullptr);
}

void DLLStructure::Sort(){ //method to sort list into ascending order
	Node* NodeA = this->first; //iterating pair of nodes
	Node* NodeB = NodeA->getNext();
	int dataA;
	int dataB;
	bool Loop = true; //loop boolean

	while (Loop)
	{ //performing bubble sort on list
		Node* NodeA = this->first; //for each iteration looping though list
		Node* NodeB = NodeA->getNext();
		Loop = false;

		do
		{
			dataA = NodeA->getData();
			dataB = NodeB->getData();

			if (dataA > dataB) //if values in wrong order swap values for the node pair
			{
				NodeA->setData(dataB);
				NodeB->setData(dataA);
				Loop = true; //list will now be iterated over one more time
			}
			NodeA = NodeA->getNext();
			NodeB = NodeB->getNext();
		} while (NodeB != nullptr);
	}
}

bool DLLStructure::IsEmpty(){ //method to check if list is empty
	Node* EmptyNode = this->first;
	if (EmptyNode->getData() == NULL) 
	{ //if list is 1 element long, and value of element is NULL, then it is empty
		return true;
	}
	else
	{
		return false;
	}
}

int DLLStructure::GetHead()
{ //method to retrieve value of first node in list
	Node* HeadNode = this->first;
	return HeadNode->getData();
}

int DLLStructure::GetTail()
{ //method to retrieve value of last node in list
	Node* TailNode = this->last;
	return TailNode->getData();
}

int DLLStructure::GetSize(){ //method to find size of list
	//could potentially be sped up by having list size as a object variable
	//and having other methods update the size variale when new nodes are added/deleted
	//then GetSize() method simply returning list size variable
	Node* Iter = this->first;
	this->size = 0;
	do
	{
		Iter = Iter->getNext();
		++this->size;

	} while (Iter != nullptr);
	return this->size;
}

int DLLStructure::GetMax()
{ //method to return max value of node
	//could be sped up in same way as explained in GetSize()
	Node* MaxNode = this->first;
	int max = 0.0001; //arbitrarily small number
	do
	{
		if (MaxNode->getData() > max)
		{
			max = MaxNode->getData();
		}
		MaxNode = MaxNode->getNext();
	} while (MaxNode != nullptr);
	return max;
}

int DLLStructure::GetMin()
{ //method to get minimum value in list
	//could be sped up up in same way as explained in GetSize()
	Node* MinNode = this->first;
	int min = 999999; //arbitrarily large number
	do
	{
		if (MinNode->getData() < min)
		{
			min = MinNode->getData();
		}
		MinNode = MinNode->getNext();
	} while (MinNode != nullptr);
	return min;
}

DLLStructure::DLLStructure(DLLStructure &dlls){
	//The default copy constructor class will only copy values of variables,
	//however the pointers will still point to objects from the list to be copied
	//this defined default constructor class creates new objects for the pointers to point to
	//correctly copying the list
	int size = dlls.GetSize();
	Node** DLList = new Node*[size];
	for (int i = 0; i<size; ++i)
	{
		DLList[i] = new Node;
	}

	Node* NodeToCopy;

	this->first = DLList[0];
	this->last = DLList[size - 1];
	this->size = dlls.GetSize();

	NodeToCopy = dlls.first;

	DLList[0]->setData(NodeToCopy->getData());
	DLList[0]->setNext(DLList[1]);
	DLList[0]->setPrevious(nullptr);

	NodeToCopy = NodeToCopy->getNext();

	for (int i = 1; i<size - 1; ++i)
	{
		DLList[i]->setData(NodeToCopy->getData());
		DLList[i]->setNext(DLList[i + 1]);
		DLList[i]->setPrevious(DLList[i - 1]);

		NodeToCopy = NodeToCopy->getNext();
	}

	DLList[size - 1]->setData(NodeToCopy->getData());
	DLList[size - 1]->setNext(nullptr);
	DLList[size - 1]->setPrevious(DLList[size - 2]);

	delete[] DLList;
}

DLLStructure::~DLLStructure()
{ //destruction method
	Node* NodeToDel = this->first;
	Node* NextNode;
	do
	{
		NextNode = NodeToDel->getNext();
		delete NodeToDel;
		NodeToDel = NextNode->getNext();
	} while (NodeToDel != nullptr);
}
