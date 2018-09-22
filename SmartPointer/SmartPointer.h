
#pragma once
#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
using namespace std;


template <class T>
class SmartPointer
{
	//instantiating SmartPointer class
public:
	//constructor methods
	SmartPointer();
	SmartPointer(T data);
	//copy constructor method
	SmartPointer(const SmartPointer& a);
	//getter and setter methods
	T getValue();
	void setValue(T data);
	//overloading assignment operator (cannot be overloaded in a friend function)
	void operator=(const T& a);

	//destructor class
	~SmartPointer();

	//defining friend methods to overload operators
	friend T operator+(const SmartPointer<T>& a, const SmartPointer<T>& b)
	{
		T result = (*(a.ptr) + *(b.ptr));
		return result;
	}
	friend T operator-(const SmartPointer<T>& a, const SmartPointer<T>& b)
	{
		T result = (*(a.ptr) - *(b.ptr));
		return result;
	}
	friend T operator*(const SmartPointer<T>& a, const SmartPointer<T>& b)
	{
		T result = (*(a.ptr) * *(b.ptr));
		return result;
	}

private:
	//defining class members
	T* ptr;

};



//instantiating exception extension methods
class OutOfMemory : public exception
{
public:
	virtual const char* what() const throw();
};


class NegativeNumAssign : public exception
{
public:
	virtual const char* what() const throw();
};

#endif