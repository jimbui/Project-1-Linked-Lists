#pragma once
#include <iostream>

using namespace std;

template<class T> class SingleNode
{
	// ??????????????????????
	friend class CyclicLinkedList;

private:
	SingleNode<T>* next;
	T data;

public:
	SingleNode(const T& Data, SingleNode<T>* Next)
	{
		data = Data;
		next = Next;
	}

	~SingleNode() {}

	T getData() const { return data; };
	SingleNode* getNext() const { return next; };

	void Display() const
	{
		cout << "Data:  " << data << endl;
		cout << "Next:  " << next << endl;
	}
};