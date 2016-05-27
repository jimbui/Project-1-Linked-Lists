#pragma once
#include <iostream>
#include "SingleNode.h"

using namespace std;

template<class T> class CyclicLinkedList
{
private:
	int size;

	SingleNode<T>* head;
	SingleNode<T>* tail;

public:

	CyclicLinkedList() :size(0), head(nullptr), tail(nullptr)
	{
	}

	~CyclicLinkedList()
	{
		// Delete all elements
	}

	int Size() const { return size; };
	bool empty() const { return head == nullptr; };

	// Edit later!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	T front() const
	{
		if (empty())
		{
			cout << "Underflow exception." << endl;
			// return an error
			return -1;
		}
		else
			return head->data;
	}

	T back() const
	{
		if (empty())
		{
			cout << "Underflow exception." << endl;
			// return an error
			return -1;
		}
		else
			return tail->data;
	}
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	int count(const T& Data) const
	{
		// Iterate through the list and increment where (data == Data).  Return counter.
		return 0;
	}

	void push_front(const T& data)
	{
		// Places an item at the front of the list and updates head pointer
	}

	void push_back(const T& data)
	{
		// Places an item at the back of the list and updates tail pointer
	}

	T pop_front()
	{
		// Deletes the first node, updates the head and tail nodes, and returns the 
		// value originally stored in that node.
	}

	int erase(const T& Data)
	{
		// Returns the number of items where (data == Data) that were deleted from the list
		return 0;
	}

	// Test method for friend class (remove later)
	T Test()
	{
		cout << "Friend test:  Input 5" << endl;
	}
};