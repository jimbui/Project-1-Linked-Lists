#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include <iostream>

using namespace std ;

template<class T> class DoubleNode // needs to test.
{
	// friend class DoublyLinkedList<T>;

public: // Make private later upon implementing friend functionality

	T data ;
	DoubleNode<T>* next ;
	DoubleNode<T>* previous ;
	
public:

	DoubleNode():data(0) , previous(nullptr) , next(nullptr){}

	DoubleNode(const T& Data , DoubleNode<T>* Previous , DoubleNode<T>* Next)
	{
		data = Data ;
		previous = Previous ;
		next = Next ;
	}

	~DoubleNode() {};

	T getData() const { return data ; } ;
	DoubleNode* getPrevious() const { return previous ; } ;
	DoubleNode* getNext() const { return next ; } ;

	void Display() const
	{
		cout << "Data:  " << data << endl ;
		cout << "Next:  " << next << endl ;
		cout << "Previous:  " << previous << endl ;
	}
} ;

#endif