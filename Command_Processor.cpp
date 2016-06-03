#include <iostream>
#include "Command_Processor.h"
using namespace std;

Command_States Command_Processor::command_state = Initial;

Menu* Command_Processor::menus[NR_CMD_STATES];

bool flag = false;

CyclicLinkedList<double> Cyclic_list; 
DoublyLinkedList<double> Doubly_list;

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
	menu->Add_Command("Print List");
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
	//CyclicLinkedList<double> Cyclic_list;  

    if (cmd == "Create Cyclic List")
    {
		if (flag == true) { cout << "The list was already created" << endl; }
        //CyclicLinkedList<double> Cyclic_list;
        else 
		{
			cout << "List created\n";
			flag = true;
			command_state = State_Selected;
		}
        
    }
    else if (cmd == "Push Front")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				double data;
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
				double data;
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
		double trouble = 0;

		try
		{
			trouble = Cyclic_list.pop_front(); // This method can throw an error instead of returning a value.
			cout << "Element Erased" << endl << endl;
		}
		catch (const underflow_error& e)
		{
			cerr << e.what() << endl;
		}
            
        command_state = State_Selected;
    }
	else if (cmd == "Erase")
    {
		double data;
            cout << "Enter value to delete\n-->";
            cin >> data;
			cin.ignore(); //due to error with next menu
            Cyclic_list.erase(data);
        cout << "Element Deleted\n";
		command_state = State_Selected;
    }
	else if (cmd == "Print List")
	{  
		if (!flag) {
                cerr << endl << "Cannot print list. List has not been created yet or is empty." << endl;
				}
		else Cyclic_list.Display();
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


     if (cmd == "Create Doubly List")
    {
		if (flag == true) { cout << "The list was already created" << endl; }
		else
		{
			cout << "List created\n";
			flag = true;
			command_state = State_Selected2;
		}
        
    }
    else if (cmd == "Push Front")
    {
		if (!flag) {
                cerr << endl << "Cannot insert element. List has not been created yet." << endl;
				}
		else {
				double data;
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
				double data;
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
		double trouble = 0;

		try
		{
			trouble = Doubly_list.pop_front(); // This method can throw an error instead of returning a value.
			cout << "Element Erased" << endl << endl;
		}
		catch (const underflow_error& e)
		{
			cerr << e.what() << endl;
		}
        command_state = State_Selected2;
    }
	else if (cmd == "Erase")
    {
		double data;
            cout << "Enter value to delete\n-->";
            cin >> data;
			cin.ignore(); //due to error with next menu
            Doubly_list.erase(data);
        cout << "Element Deleted\n";
		command_state = State_Selected2;
    }
	else if (cmd == "Print List")
	{  
		if (!flag) {
                cerr << endl << "Cannot print list. List has not been created yet or is empty." << endl;
				}
		else Doubly_list.Display();
		command_state = State_Selected2;

	}
    else
    {
        command_state = Done;
    }
}