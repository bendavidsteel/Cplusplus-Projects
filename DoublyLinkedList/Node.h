#pragma once
#ifndef NODE_H
#define NODE_H

class Node
{
public:
	//constructor methods
	Node();
	Node(int data, Node* next, Node* previous);
	//setter methods
	void setData(int data);
	void setNext(Node* next);
	void setPrevious(Node* previous);
	//getter classes
	int getData();
	Node* getNext();
	Node* getPrevious();
	//destructor class
	~Node();

private:
	//declaring object variables
	int data;
	Node* next;
	Node* previous;
};

#endif