Project 01 - Linked Lists
Programmers:  Manuel Martinez, John Santoro, and Jim Bui

The driver program, main.cpp, utilizes a command processor and a menu class (Command_Processor.h and Command_Processor.cpp; Menu.h and Menu.cpp respectively) in order to display information about the cyclic linked list and the doubly linked list.  The command processor requires the user to enter a numeric input in order to progress to the next menu or perform a certain function.  For example, 

1: Cyclic Linked List
2: Doubly Linked List
3: Quit

> [A numeric value expected]

Typing in 1 and hitting enter on this menu will give the user access to all of the functions associated with the cyclic linked list.  This is the full menu layout, along with a description of what each of the functions accomplish:

1: Cyclic Linked List
--> Goes to
	1: Create Cyclic List - Creates a new cyclic linked list, if one does not already exist
	2: Delete List - Deletes the current cyclic list using the custom destructor
	3: Size - Calls Size() in cyclic linked list, which returns the size of the list
	4: Empty - Calls empty() in cyclic linked list, which returns whether the list is empty
	5: Print Front Data - Calls front() in cyclic linked list, which throws an underflow error if the list is empty and returns the data in the head pointer if it is not
	6: Print Back Data - Calls back() in cyclic linked list, which throws an underflow error if the list is empty and returns the data in the tail pointer if it is not
	7: Print Head Address - Calls head() in cyclic linked list and prints the value of the head pointer
	8: Print Tail Address - Calls tail() in cyclic linked list and prints the value of the tail pointer
	9: Count - Calls count(T value) in cyclic linked list, which returns the number of elements equal to the value specified in the argument
	10: Push Front - Calls push_front(T value) in cyclic linked list, which adds an element of the value specified to the front of the list and updates the pointers
	11: Push Back - Calls push_back(T value) in cyclic linked list, which adds an element of the value specified to the back of the list and updates the pointers
	12: Pop Front - Calls pop_front() in cyclic linked list, which deletes the first element and returns its value if there is a first element; otherwise, it throws an underflow error
	13: Erase - Calls erase(T value) in cyclic linked list, which erases all elements of a user-defined value and then returns the number of elements erased
	14: Print List - Calls Display() in cyclic linked list, which shows all of the elements from front to back.
	15: Return to previous menu
<-- Goes Back
	16: Quit					--> Exit Program
2: Doubly Linked List
--> Goes to
	1: Create Cyclic List - Creates a new doubly linked list, if one does not already exist
	2: Delete List - Deletes the current doubly list using the custom destructor
	3: Size - Calls Size() in doubly linked list, which returns the size of the list
	4: Empty - Calls empty() in doubly linked list, which returns whether the list is empty
	5: Print Front Data - Calls front() in doubly linked list, which throws an underflow error if the list is empty and returns the data in the head pointer if it is not
	6: Print Back Data - Calls back() in doubly linked list, which throws an underflow error if the list is empty and returns the data in the tail pointer if it is not
	7: Print Head Address - Calls head() in doubly linked list and prints the value of the head pointer
	8: Print Tail Address - Calls tail() in doubly linked list and prints the value of the head pointer
	9: Count - Calls count(T value) in doubly linked list, which returns the number of elements equal to the value specified in the argument
	10: Push Front - Calls push_front(T value) in doubly linked list, which adds an element of the value specified to the front of the list and updates the pointers
	11: Push Back - Calls push_back(T value) in doubly linked list, which adds an element of the value specified to the back of the list and updates the pointers
	12: Pop Front - Calls pop_front() in doubly linked list, which deletes the first element and returns its value if there is a first element; otherwise, it throws an underflow error
	13: Erase - Calls erase(T value) in doubly linked list, which erases all elements of a user-defined value and then returns the number of elements erased
	14: Print List - Calls Display() in doubly linked list, which shows all of the elements from front to back.
	15: Return to previous menu
<-- Goes Back
	16: Quit					--> Exit Program
3: Quit						--> Exit Program
