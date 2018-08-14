#include "SmartPointer.h"
#include <iostream>
using namespace std;

//smart pointers hold pointers, and ensure they are deleted on destruction
//this helps prevent memory leak and  hanging references
//this is useful in code where functions and methods might return or throw exceptions before pointers can be deleted
//There are 3 types of pointers provided with C++11

//(1) unique_ptr

//unique_ptr simply holds a pointer, and ensures that the pointer is deleted on destruction. unique_ptr objects cannot be copied
//unique_ptr also has defined move contructors, allowed safe transfer of a pointer being pointed to between unique_ptr objects

//(2) shared_ptr

//shared_ptr has all the features of unique_ptr, but with the added benefit of being copyable
//the class ensures the pointer has been deleted once all shared_ptr objects that were holding it are destroyed (or have released it)
//this is ensured using reference counting, which uses atomic functions, meaning shared_ptr is thread safe

//(3) weak_ptr

//weak_ptr is used to hold a non owning reference to a pointer that is managed by a shared_ptr
//it must be converted to shared_ptr before it can access the pointer it is referencing
//when an object needs to be accessed only if it exists, and it may be deleted at any time by someone else, weak_ptr is used to track the object
//it is primarily useful when it is needed to break circular references

int main()
{
	try
	{
		//testing constructor
		SmartPointer<int> sPointer1(11);
		cout << sPointer1.getValue() << endl; // prints 11
		//testing default constructor and set value
		SmartPointer<int> sPointer2;
		sPointer2.setValue(13);
		cout << sPointer2.getValue() << endl; // prints 13
		//testing with type float
		SmartPointer<float> sPointer3;
		sPointer3.setValue(13.31f);
		cout << sPointer3.getValue() << endl; // prints 13.31
		//testing with type double
		SmartPointer<double> sPointer4;
		sPointer4.setValue(13.31);
		cout << sPointer4.getValue() << endl; // prints 13.31
		//testing addition operator overload
		SmartPointer<int> sPointer5;
		sPointer5 = sPointer1 + sPointer2;
		cout << sPointer5.getValue() << endl; // prints 24
		//testing minus operator overload
		sPointer5 = sPointer2 - sPointer1;
		cout << sPointer5.getValue() << endl; // prints 2
		//testing multiplication operator overload
		sPointer5 = sPointer1 * sPointer2;
		cout << sPointer5.getValue() << endl; // prints 143
		//testing negative value assignment error
		SmartPointer<int> sPointer6;
		sPointer6.setValue(-13);              // prints an error
		cout << sPointer6.getValue() << endl; 
	}
	catch (OutOfMemory& memE)
	{
		//catching and printing in the event of out of memory error
		cout << memE.what() << endl;
	}
	catch (NegativeNumAssign& memN)
	{
		//catching and printing in the event of negative number assignment error
		cout << memN.what() << endl;
	}

	return 0;
}