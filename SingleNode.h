#ifndef SINGLENODE_H
#define SINGLENODE_H

#include <iostream>

using namespace std ;

template<class T> class SingleNode
{	
	template<class U> friend class CyclicLinkedList ; // this is the line that makes it bffs.

private:

	T data ;
	SingleNode<T>* next ;

public:

	SingleNode():data(0) , next(nullptr){}

	SingleNode(const T& Data , SingleNode<T>* Next)
	{
		data = Data ;
		next = Next ;
	}

	~SingleNode(){}

	T getData() const { return data ; } ;
	SingleNode* getNext() const { return next ; } ;

	void Display() const
	{
		cout << "Data:  " << data << endl ;
		cout << "Next:  " << next << endl << endl ;
	}
} ;

#endif