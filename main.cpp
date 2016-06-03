#include <iostream>
#include "SingleNode.h"
#include "DoubleNode.h"
#include "DoublyLinkedList.h"
#include "CyclicLinkedList.h"
#include "Command_Processor.h"

using namespace std ;

// node tests.

void Single_Node_Test() ;
void Double_Node_Test() ;

// cyclic-linked list tests.

void Random_Test() ;
void Random_Test_Twooo() ;
void Exception_Test() ;

// doubly-linked list tests.

void PushFrontAndBack(DoublyLinkedList<double>& list) ;
void PrintDoubleList(const DoublyLinkedList<double>& list) ;
void TestUnderflowErrors(const DoublyLinkedList<double>& list) ;
void TestDoublyLinkedList() ; // test all.

// test pop front doubly

void pop_front_doubly_test();

// main.

int main()
{
	// the while loop is for clearing the command prompt on linux.

	/*

	int i = 0 ;

	while (i < 50)
	{
		std::cout << std::endl ;
		i++ ;
	}

	*/

	std::cout << std::endl << "El Team Projecto Numero 1" << std::endl << std::endl ;

	

	//Single_Node_Test();
	//Double_Node_Test() ;
	//TestDoublyLinkedList() ;
	//Random_Test() ;
	//Random_Test_Twooo() ;
	//Exception_Test() ;
	//pop_front_doubly_test();

	Command_Processor::Process_Commands();

	std::cout << endl ;

	cin.get();
	return 0;
}

void pop_front_doubly_test()
{
	DoublyLinkedList<double> test_list;
	// print empty list
	test_list.Display();
	cout << test_list.Size() << endl;

	//test_list.pop_front();  //exception
		

	test_list.push_back(23);
	test_list.push_back(56);
	test_list.push_front(47);

	test_list.Display();

	//test pop front
	test_list.pop_front();

	test_list.Display();

}

// node tests.

void Single_Node_Test()
{
	cout << "single node test: " << endl << endl ;
	SingleNode<int> doubleNode3() ;
	SingleNode<float> whatisthis(0 , nullptr) ;
	SingleNode<double> doubleNode2(12.3456789 , nullptr) ;
	SingleNode<double> doubleNode1(3.14 , &doubleNode2) ;

	doubleNode1.Display() ;
	doubleNode2.Display() ;
	
	cout << doubleNode1.getData() << endl ;
	cout << doubleNode1.getNext() << endl << endl ;
}

void Double_Node_Test() 
{
	cout << "double node test: " << endl << endl ;
	DoubleNode<float> doubleNode0() ;
	DoubleNode<int> doubleNode1(0 , nullptr , nullptr) ;
	DoubleNode<int> doubleNode3(0 , nullptr , nullptr) ;
	DoubleNode<int> doubleNode2(10 , &doubleNode1 , &doubleNode3) ;

	doubleNode2.Display() ;
} 

// cyclic-linked list tests.

void Random_Test()
{
	CyclicLinkedList<int> the_list ;
	std::cout << the_list.Size() << endl ;

	if (the_list.empty())
		std::cout << "empty." << endl ;

	std::cout << the_list.front() << endl ;
	std::cout << the_list.back() << endl ;
	the_list.push_front(99999) ;
	the_list.push_front(123) ;
	the_list.push_front(123) ;
	the_list.push_front(123) ;
	the_list.push_front(123) ;
	the_list.push_front(888) ;
	std::cout << the_list.front() << endl ;
	std::cout << the_list.back() << endl ;
	the_list.push_back(666) ;
	std::cout << the_list.back() << endl ;
	the_list.Display() ;
	std::cout << "count of number 123:  " << the_list.count(123) << std::endl ;
	the_list.pop_front() ;
	the_list.Display() ;
	// std::cout << std::endl << "CYCLIC CHECK BEGIN: " << std::endl << std::endl ;
	// the_list.Cyclic_Check() ;
	std::cout << "let's delete 123:  " << the_list.erase(123) << " deleted." << std::endl ;
	the_list.Display() ;
}

void Random_Test_Twooo()
{
	CyclicLinkedList<int> the_list ; // an empty list.
	the_list.Display() ;
	the_list.pop_front() ;
	the_list.Display() ;
	std::cout << the_list.erase(12) << std::endl ;
	the_list.Display() ;
	// the_list.push_back(12) ;
	the_list.push_front(13) ;
	the_list.Display() ; 
	the_list.Cyclic_Check() ;
}

void Exception_Test()
{
	CyclicLinkedList<int> the_list ;
	the_list.pop_front() ;
}

// doubly-linked list tests.

void TestDoublyLinkedList()
{
	DoublyLinkedList<double> d;

	cout << "----------------------------Print w/ empty list----------------------------" << endl;
	PrintDoubleList(d);

	cout << endl;

	// Please review the front and back methods of the DoublyLinkedList class.
	cout << "-----------Error Test - Retrieve Front and Back From Empty List------------" << endl;
	TestUnderflowErrors(d);
	cout << endl << "Notice how the error messages appear in the output window." << endl;

	cout << endl;

	// Inputs some items into the list.  Push front adds an item to the front of the list, and 
	// push back adds an item to the back of the list.
	PushFrontAndBack(d);

	// Prints the list again with the added items
	cout << "----------------------------Print w/ full list-----------------------------" << endl;
	PrintDoubleList(d);

	cout << endl;

	// Test deletion
	cout << "-------------------------------Deletion Test-------------------------------" << endl;
	int deletion_count = d.erase(0.4);
	cout << "Deleting 0.4 from list:  Number of deletions - " << deletion_count << endl;
	deletion_count = d.erase(3.14159265358);
	cout << "Deleting 3.14159265358 from list:  Number of deletions - " << deletion_count << endl;
	deletion_count = d.erase(1.2);
	cout << "Deleting 1.2 from list:  Number of deletions - " << deletion_count << endl;
	deletion_count = d.erase(8.9);
	cout << "Deleting 8.9 from list:  Number of deletions - " << deletion_count << endl;
	deletion_count = d.erase(10.1);
	cout << "Deleting 10.1 from list:  Number of deletions - " << deletion_count << endl;
	deletion_count = d.erase(4.6);
	cout << "Deleting 4.6 from list:  Number of deletions - " << deletion_count << endl;

	PrintDoubleList(d);
}

// DoublyLinkedList Tests

void PushFrontAndBack(DoublyLinkedList<double>& list)
{
	list.push_front(4.6);
	list.push_back(0.4);
	list.push_front(1.2);
	list.push_front(4.6);
	list.push_front(8.9);
	list.push_back(10.1);
	list.push_back(4.6);
	list.push_front(4.6);
	list.push_front(4.6);
}

void TestUnderflowErrors(const DoublyLinkedList<double>& list)
{
	double trouble = 0;

	// In order to perform error checking, you should use a try block.
	// try {...} will check and see if an error was thrown in the method it encapsulates, and
	// catch (const ...& e) { cerr << e.what() << endl; } will catch the error and display 
	// its information to the user.

	// back()
	try
	{
		trouble = list.back(); // This method can throw an error instead of returning a value.
		cout << "Back of list:  " << trouble << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}

	// front()
	try
	{
		trouble = list.front(); // This method can throw an error instead of returning a value.
		cout << "Front of list:  " << trouble << endl;
	}
	catch (const underflow_error& e)
	{
		cerr << e.what() << endl;
	}
}

void PrintDoubleList(const DoublyLinkedList<double>& list)
{
	int counter = 0;

	// Display size
	cout << "Size of list = " << list.Size() << endl;

	// Print list forwards
	cout << "Forward Print:  " << endl << endl << "Head <===>" << endl;
	for (DoubleNode<double>* p = list.Head(); p != nullptr; p = p->getNext())
	{
		cout << "Item[" << counter++ << "] = " << p->getData() << " <===>" << endl;
	}
	cout << "Tail" << endl << endl;

	// Print list backwards
	cout << "Backward Print:  " << endl << endl << "Tail <===>" << endl;
	for (DoubleNode<double>* p = list.Tail(); p != nullptr; p = p->getPrevious())
	{
		cout << "Item[" << --counter << "] = " << p->getData() << " <===>" << endl;
	}
	cout << "Head" << endl;
}