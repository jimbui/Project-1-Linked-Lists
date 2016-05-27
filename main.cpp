#include <iostream>
#include "SingleNode.h"
#include "DoubleNode.h"

using namespace std ;

void Single_Node_Test() ;
void Double_Node_Test() ;

int main()
{
	cout << endl << "El Team Projecto Numero 1" << endl << endl ;

	Single_Node_Test() ;
	Double_Node_Test() ;

	cout << endl ;
	return 666 ;
}

// tests.

void Single_Node_Test() 
{
	cout << "single node test: " << endl << endl ;
	SingleNode<int> doubleNode3() ;
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