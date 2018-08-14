#include "SmartPointer.h"
#include <iostream>
using namespace std;

const char* OutOfMemory::what() const throw()
{
	//extending exception class
	//out of memory error
	return "Warning: Out Of Memory";
}
//creating throwable object
OutOfMemory memoryException;

const char* NegativeNumAssign::what() const throw()
{
	//extending exception class
	//negative number assignment error
	return "Cannot Assign Negative Number to Smart Pointer";
}
//creating throwable object
NegativeNumAssign negativeException;


template <class T>
SmartPointer<T>::SmartPointer()
{
	//default constructor definition
	try
	{
		this->ptr = new T;
		*(this->ptr) = 0;
	}
	catch (bad_alloc& e) 
	{
		//catching out of memory error
		cout << e.what() << endl;
		throw memoryException;
	}
}

template <class T>
SmartPointer<T>::SmartPointer(T data)
{
	//constructor method definition
	//checking for negative number assignment
	if (data < 0)
	{
		throw negativeException;
	}
	try
	{
		//assigning data to pointer
		this->ptr = new T;
		*(this->ptr) = data;
	}
	catch (bad_alloc& e)
	{
		//catching out of memory error
		cout << e.what() << endl;
		throw memoryException;
	}
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer& a)
{
	//copy constructor definition
	this->setValue(*a.ptr);
}

template <class T>
T SmartPointer<T>::getValue()
{
	//return data pointer points to
	return *(this->ptr);
}

template <class T>
void SmartPointer<T>::setValue(T data)
{
	//set value pointer points to
	//checking for negative number assignment
	if (data < 0)
	{
		throw negativeException;
	}
	*(this->ptr) = data;
}

template <class T>
void SmartPointer<T>::operator=(const T& a)
{
	//overloading assignment operator
	this->setValue(a);
}

template <class T>
SmartPointer<T>::~SmartPointer()
{
	//destructor method definiton
	delete this->ptr;
}

//allows separate instantiation and definition in a header file and cpp file
template class SmartPointer<int>;
template class SmartPointer<float>;
template class SmartPointer<double>;

