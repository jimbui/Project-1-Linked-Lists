#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept> // underflow_error depends on this library.
#include "DoubleNode.h"

using namespace std ;

template<class T> class DoublyLinkedList
{

private:
	int size ;

	DoubleNode<T>* head ;
	DoubleNode<T>* tail ;

public:

	DoublyLinkedList():size(0) , head(nullptr) , tail(nullptr){}

	~DoublyLinkedList()
	{
		// delete all nodes in list.
	}

	int Size() const { return size ; } ;
	bool empty() const { return head == nullptr ; } ;
	DoubleNode<T>* Head() const { return head; };
	DoubleNode<T>* Tail() const { return tail; };

	T front() const // incomplete.
	{
		// This is how to throw an error -- the error must also be caught or it will cause the program to stop functioning.
		if (empty())
			throw underflow_error("The list is empty; underflow exception thrown."); 
		else
			return head->getData();
	}

	T back() const // incomplete.
	{
		if (empty())
			throw underflow_error("The list is empty; underflow exception thrown.");
		else
			return tail->getData();
	}

	int count(const T& Data) const // iterate through the list and increment where (data == Data).  return counter.
	{
		return 0 ;
	}

	void push_front(const T& data) // places an item at the front of the list and updates head pointer.
	{
		// The list is empty
		if (head == nullptr)
		{
			head = new DoubleNode<T>(data, nullptr, nullptr);
			tail = head;
		}
		else // The list only has one or more items
		{
			DoubleNode<T>* new_node = new DoubleNode<T>(data, nullptr, head);
			head = new_node;
			head->getNext()->previous = new_node;
		}

		size++;
	}

	void push_back(const T& data) // Places an item at the back of the list and updates tail pointer
	{
		// The list is empty
		if (head == nullptr)
		{
			head = new DoubleNode<T>(data, nullptr, nullptr);
			tail = head;
		}
		else // The list only has one or more items
		{
			DoubleNode<T>* new_node = new DoubleNode<T>(data, tail, nullptr);
			tail = new_node;
			tail->getPrevious()->next = new_node;
		}

		size++;
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
		int num_values_deleted = 0;
		
		if (head == nullptr) // No items could be deleted because the list was empty
			return num_values_deleted;

		DoubleNode<T>* cur = head;
		DoubleNode<T>* previous = nullptr;

		//int stopThisLoop = 0;

		while (cur != nullptr)
		{
			if (cur->getData() == Data)
			{
				num_values_deleted++;
				size--;

				if (previous == nullptr)  // The item to be deleted is the first in the list
				{
					head = cur->getNext();
					delete cur;

					if (head == nullptr)
					{
						tail = nullptr;
						break;
					}

					head->previous = nullptr;
					cur = head;
				}
				else if (cur->getNext() == nullptr)  // The item to be deleted is at the end of the list
				{
					previous->next = nullptr;
					delete cur;
					tail = previous;
					cur = nullptr;
				}
				else // The item to be deleted is somewhere in the middle of the list
				{
					previous->next = cur->getNext();
					delete cur;
					previous->getNext()->previous = previous;
					cur = previous->getNext();
				}
			}
			else // Simply traverse the list
			{
				previous = cur;
				cur = cur->getNext();
			}
		}

		

		return num_values_deleted;
	}
} ;

#endif
