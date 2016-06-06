#ifndef CYCLICLINKEDLIST_H
#define CYCLICLINKEDLIST_H

#include <iostream>
#include <stdexcept> // underflow_error depends on this library.
#include "SingleNode.h"

using namespace std ;

template<class T> class CyclicLinkedList
{
private:

	int size ;

	SingleNode<T>* head ;
	SingleNode<T>* tail ;

public:

	CyclicLinkedList():size(0) , head(nullptr) , tail(nullptr){} // good.

	~CyclicLinkedList()
	{
		while (head != nullptr)
		{
			pop_front();
		}

	} 

	int Size() const {return this->size ; } ; // good.
	bool empty() const {return this->head == nullptr ; } ; // good.
	SingleNode<T>* Head() const { return head; };
	SingleNode<T>* Tail() const { return tail; };

	T front() const // returns the data member of the head node.
	{
		if (this->empty())
		{
			throw underflow_error("the list is empty , underflow exception.") ;
			// std::cout << "the list is empty , sorry fam.  " ; return -1 ; // for testing purposes.
		}

		else
			return this->head->data ;
	}

	T back() const // returns the data member of the tail node.
	{
		if (this->empty())
		{
			throw underflow_error("the list is empty , underflow exception.") ;
			// std::cout << "the list is empty , sorry fam.  " ; return -1 ; // for testing purposes.
		}

		else
			return this->tail->data ;
	}

	int count(const T& Data) const // iterate through the list and increment where (data == Data).  return counter.
	{
		SingleNode<T>* current_node = head ;
		int i = 0 ;

		if (this->empty())
			return i ;

		else
		{
			while (current_node->next != head)
			{
				if (current_node->data == Data)
					i++ ;
				current_node = current_node->next ;
			}

			if (current_node->data == Data)
					i++ ;

			return i ;
		}
	}

	void push_front(const T& data) // places an item at the front of the list.
	{
		if (this->empty()) 
		{
			this->head = new SingleNode<T>(data , nullptr) ;
			this->head->next = head ;
			this->tail = head ;
			this->tail->next = head ;
		} 

		else
		{
			SingleNode<T>* new_node = new SingleNode<T>(data , head) ;
			this->tail->next = new_node ; 
			this->head = new_node ;
		}

		size++ ;
	}

	void push_back(const T& data) // Places an item at the back of the list and updates tail pointer
	{
		if (this->empty()) 
		{
			this->head = new SingleNode<T>(data , nullptr) ;
			this->head->next = head ;
			this->tail = head ;
			this->tail->next = head ;
		} 

		else
		{
			SingleNode<T>* new_node = new SingleNode<T>(data , head) ;
			this->tail->next = new_node ; 
			this->tail = new_node ;
		}

		size++ ;
	}

	T pop_front()
	{
		// deletes the first node , updates the head and tail nodes
		// returns the value originally stored in that node.  (or is it return the new value in the node?)
		// underflow exception if empty.
		if (this->empty())
		{
			throw underflow_error("the list is empty , underflow exception.") ;
			// std::cout << "the list is empty , sorry fam.  " ; return -1 ; // for testing purposes.
		}

		else if (size == 1)
		{
			T data_temp = head->data ;
			delete this->head ;
			this->head = nullptr ;
			this->tail = nullptr ; 
			size-- ;
			return data_temp ;
		}

		else
		{
			T data_temp = head->data ;
			this->tail->next = this->head->next ;
			delete this->head ;
			this->head = this->tail->next ;
			size-- ;
			return data_temp ;
		}
	}

	int erase(const T& Data)
	{
		// delete nodes with (data == Data).
		// returns the number of items deleted.
		int num_values_deleted = 0;

		if (head == nullptr) // No items could be deleted because the list was empty
			return num_values_deleted;

		SingleNode<T>* cur = head;
		SingleNode<T>* previous = nullptr;

		int stopThisLoop = size;

		while (stopThisLoop > 0)
		{
			if (cur->getData() == Data)
			{
				num_values_deleted++;
				size--;

				if (previous == nullptr)  // The item to be deleted is the first in the list
				{
					head = cur->getNext();

					delete cur;

					if (size == 0)
					{ 
						head = nullptr;
						tail = nullptr;
						break;
					}

					// head->previous = nullptr;
					tail->next = head;
					cur = head;
					int duh = 0;
				}
				else if (cur->getNext() == nullptr)  // The item to be deleted is at the end of the list
				{
					previous->next = head;
					delete cur;
					tail = previous;
					cur = nullptr;
				}
				else // The item to be deleted is somewhere in the middle of the list
				{
					previous->next = cur->getNext();
					delete cur;
					// previous->getNext()->previous = previous;
					cur = previous->getNext();
				}
			}
			else // Simply traverse the list
			{
				previous = cur;
				cur = cur->getNext();
			}

			stopThisLoop--;
		}

		return num_values_deleted;
	}

	// for testing purposes.

	void Display() 
	{
		int i = 1 ;
		SingleNode<T>* current_node = head ;

		if (this->empty())
			std::cout << "The list is empty." << std::endl ;
/*
		else if (this->size == 1)
		{
			std::cout << i << ":  " << current_node->data << std::endl ;
		}
*/
		else
		{
			while (current_node->next != head)
			{
				std::cout << i << ":  " << current_node->data << std::endl ;
				current_node = current_node->next ;
				i++ ;
			}

			if (current_node != nullptr)
				std::cout << i << ":  " << current_node->data << std::endl ;
		}
	}

	void Cyclic_Check() // done.
	{
		int i = 1 ;
		SingleNode<T>* current_node = head ;

		if (this->empty())
			std::cout << "The list is empty." << std::endl ;

		else
		{
			while (i <= 100)
			{
				std::cout << i << ":  " << current_node->data << std::endl ;
				current_node = current_node->next ;
				i++ ;
			}
		}
	}
} ;

#endif
