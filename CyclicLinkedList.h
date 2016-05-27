#ifndef CYCLICLINKEDLIST_H
#define CYCLICLINKEDLIST_H

#include <iostream>
#include "SingleNode.h"

using namespace std ;

template<class T> class CyclicLinkedList
{
private:

	int size ;

	SingleNode<T>* head ;
	SingleNode<T>* tail ;

public:

	CyclicLinkedList():size(0) , head(nullptr) , tail(nullptr){}

	~CyclicLinkedList()
	{
		// delete all nodes in list.
	}

	int Size() const { return size ; } ; 
	bool empty() const { return head == nullptr ; } ;

	T front() const // incomplete.
	{
		if (empty())
		{
			cout << "the list is empty , underflow exception." << endl ;
			return -1 ;
		}

		else
			return head->data ;
	}

	T back() const // incomplete.
	{
		if (empty())
		{
			cout << "the list is empty , underflow exception." << endl ;
			return -1 ;
		}

		else
			return tail->data ;
	}

	int count(const T& Data) const // iterate through the list and increment where (data == Data).  return counter.
	{
		return 0 ;
	}

	void push_front(const T& data) // places an item at the front of the list and updates head pointer.
	{
	}

	void push_back(const T& data) // Places an item at the back of the list and updates tail pointer
	{
	}

	T pop_front()
	{
		// deletes the first node , updates the head and tail nodes
		// returns the value originally stored in that node.  (or is it return the new value in the node?)
		// underflow exception if empty.
	}

	int erase(const T& Data)
	{
		// delete nodes with (data == Data).
		// returns the number of items deleted.

		return 0 ;
	}
} ;

#endif