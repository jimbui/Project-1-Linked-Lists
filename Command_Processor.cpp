#include <iostream>
#include "Command_Processor.h"
using namespace std;

Command_States Command_Processor::command_state = Initial;

Menu* Command_Processor::menus[NR_CMD_STATES];

bool flag = false;

void Command_Processor::Create_Menus()
{
    // Menu for Initial command state
    Menu* menu = new Menu("Enter command number");
    menu->Add_Command("Cyclic Linked List");
	menu->Add_Command("Doubly Linked List");
    menu->Add_Command("Quit");
    menus[0] = menu;

    
    menu = new Menu("Enter command number");
    menu->Add_Command("Create Cyclic List");
	menu->Add_Command("Push Front");
	menu->Add_Command("Push Back");
	menu->Add_Command("Pop Front");
	menu->Add_Command("Erase");
    menu->Add_Command("Quit");
    menus[1] = menu;


	menu = new Menu("Enter command number");
    menu->Add_Command("Create Doubly List");
	menu->Add_Command("Push Front");
	menu->Add_Command("Push Back");
	menu->Add_Command("Pop Front");
	menu->Add_Command("Erase");
	menu->Add_Command("Print List");
    menu->Add_Command("Quit");
    menus[2] = menu;
}

void Command_Processor::Process_Commands()
{
    cout << "Process_Commands starting\n";

	Create_Menus();

    while (command_state != Done)
    {
       
        const string* cmd = menus[command_state]->Get_Command();


        switch (command_state)
        {
        case Initial:   Process_Command_0(*cmd);
            break;

        case State_Selected:    Process_Command_1(*cmd);
            break;

		case State_Selected2:    Process_Command_2(*cmd);
            break;

        case Done:  break;      // Can't happen
        }
    }

   cout << "Process_Commands  exiting\n";
}



// Process command in Initial command state
void Command_Processor::Process_Command_0(const string& cmd)
{
    if (cmd == "Cyclic Linked List")
    {
        cout << "Select Cyclic Command\n";
        command_state = State_Selected;
    }
	else if (cmd == "Doubly Linked List")
    {
        cout << "Select Doubly Command\n";
        command_state = State_Selected2;
    }
    else
    {
        command_state = Done;
    }
}

// Process command in Cyclic Linked List command state
void Command_Processor::Process_Command_1(const string& cmd)
{
	CyclicLinkedList<double> Cyclic_list;  //Does this go before the cmd?

    if (cmd == "Create Cyclic List")
    {
        CyclicLinkedList<double> Cyclic_list;
        cout << "List created\n";
		flag = true;
		command_state = State_Selected;
        
    }
    else if (cmd == "Push Front")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				char data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
				cin.ignore(); //due to error with next menu
				Cyclic_list.push_front(data);

				cout << "Element Inserted" << endl << endl;
            }
			
        command_state = State_Selected;
    }
	else if (cmd == "Push Back")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				char data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
				cin.ignore(); //due to error with next menu
				Cyclic_list.push_back(data);

				cout << "Element Inserted" << endl << endl;
            }
			
        command_state = State_Selected;
    }
	else if (cmd == "Pop Front")
	{

				Cyclic_list.pop_front();

				cout << "Element Inserted" << endl << endl;
            
			
        command_state = State_Selected;
    }
	else if (cmd == "Erase")
    {
		char data;
            cout << "Enter value to delete\n-->";
            cin >> data;
			cin.ignore(); //due to error with next menu
            Cyclic_list.erase(data);
        cout << "Element Deleted\n";
		command_state = State_Selected;
    }
    else
    {
        command_state = Done;
    }
}


// Process command in Doubly Linked List command state
void Command_Processor::Process_Command_2(const string& cmd)
{
	DoublyLinkedList<double> Doubly_list;

     if (cmd == "Create Doubly List")
    {
        CyclicLinkedList<double> Doubly_list;
        cout << "List created\n";
		flag = true;
		command_state = State_Selected2;
        
    }
    else if (cmd == "Push Front")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				char data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
				cin.ignore(); //due to error with next menu
				Doubly_list.push_front(data);

				cout << "Element Inserted" << endl << endl;
            }
			
        command_state = State_Selected2;
    }
	else if (cmd == "Push Back")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				char data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
				cin.ignore(); //due to error with next menu
				Doubly_list.push_back(data);

				cout << "Element Inserted" << endl << endl;
            }
			
        command_state = State_Selected2;
    }
	else if (cmd == "Pop Front")
	{

				Doubly_list.pop_front();

				cout << "Element Inserted" << endl << endl;
            
			
        command_state = State_Selected2;
    }
	else if (cmd == "Erase")
    {
		char data;
            cout << "Enter value to delete\n-->";
            cin >> data;
			cin.ignore(); //due to error with next menu
            Doubly_list.erase(data);
        cout << "Element Deleted\n";
		command_state = State_Selected2;
    }
	else if (cmd == "Print List")
	{  
		int counter = 0;

	// Display size
	cout << "Size of list = " << Doubly_list.Size() << endl;

	// Print list forwards
	cout << "Forward Print:  " << endl << endl << "Head <===>" << endl;
	for (DoubleNode<double>* p = Doubly_list.Head(); p != nullptr; p = p->getNext())
	{
		cout << "Item[" << counter++ << "] = " << p->getData() << " <===>" << endl;
	}
	cout << "Tail" << endl << endl;

	// Print list backwards
	cout << "Backward Print:  " << endl << endl << "Tail <===>" << endl;
	for (DoubleNode<double>* p = Doubly_list.Tail(); p != nullptr; p = p->getPrevious())
	{
		cout << "Item[" << --counter << "] = " << p->getData() << " <===>" << endl;
	}
	cout << "Head" << endl;

	cout << "-----------------------------------------" << endl << endl << endl;
	
	command_state = State_Selected2;

	}
    else
    {
        command_state = Done;
    }
}
