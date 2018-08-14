#include "Node.h"

//default constructor class
Node::Node()
{
}
//constructor class
Node::Node(int data, Node* next, Node* previous)
{
	this->data = data;
	this->next = next;
	this->previous = previous;
}
//set data method
void Node::setData(int data)
{
	this->data = data;
}
//set next pointer method
void Node::setNext(Node* next)
{
	this->next = next;
}
//set previous pointer method
void Node::setPrevious(Node* previous)
{
	this->previous = previous;
}
//return data method
int Node::getData()
{
	return this->data;
}
//return next pointer method
Node* Node::getNext()
{
	return this->next;
}
//return previous pointer method
Node* Node::getPrevious()
{
	return this->previous;
}
//destructor method
Node::~Node()
{
	delete this;
}
