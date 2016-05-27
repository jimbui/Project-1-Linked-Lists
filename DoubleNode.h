#pragma once
#include <iostream>

using namespace std;

// Test it later
template<class T> class DoubleNode
{
	// ?????????????????????????????
	friend class DoublyLinkedList;

private:
	DoubleNode<T>* next;
	DoubleNode<T>* previous;
	T data;

public:
	DoubleNode(const T& Data, DoubleNode<T>* Previous, DoubleNode<T>* Next)
	{
		data = Data;
		previous = Previous;
		next = Next;
	}

	~DoubleNode() {}

	T getData() const { return data; };
	DoubleNode* getPrevious() const { return previous; };
	DoubleNode* getNext() const { return next; };

	// Test method (remove later)
	void Display() const
	{
		cout << "Data:  " << data << endl;
		cout << "Next:  " << next << endl;
		cout << "Previous:  " << previous << endl;
	}
};