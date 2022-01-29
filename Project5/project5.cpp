#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "List.h"
#include "List.cpp"

using namespace std;

//function prototype
void showmenu();
//This function has better framework for user to perform an operation.
//It indicates and clarifies what characters are to be used inorder to perform required operation in a call function.

int main()
{
    list list1; //object in the class that can call the class's function
    int v; 
    char choice; //the type of character that keeps track of the operations to be carried out

    showmenu(); //this function is called to give user different options

    while (choice != 'q') //Unlimited operations can be performed unless the command q is given
						//exit option
    {
        cout << " -->";
        cin >> choice; 
        switch (choice)
        {
		//makes the call list empty
		case 'e':
            list1.a_empty(); 
            break;
		//enter items to store them in the list
        case 'i':
            cin >> v; 
            list1.insert(v);
            break; 
		//remove the values entered in the list
		case 'r':
            cin >> v; 
            list1.remove(v);
		//checks if the list is empty
		case 'm':
            if (list1.b_Empty()) 
                cout << " The list is empty.\n";
            else
                cout << " The list is not empty.\n";
            break;
		//returns the length
        case 'l':
            if (list1.length() < 1)
                cout << " The length of the given list is zero.\n";
            else 
                cout << " The length of the given list is: " << list1.length() << endl;
            break;
		//checks the values
        case 'p':
            cin >> v; 
            if (list1.isPresent(v))
                cout << " The value " << v << " is present in the list.\n";
            else
                cout << " The value " << v << " is NOT present in the list.\n";
            break; 
		//get the position 
        case 'k':
            cin >> v;
            if ((list1.bEmpty()) || (v > list1.length()))
                cout << " Not the valid selection.\n";
            else
                cout << " The " << v << "th element of the list is: " << list1.kth(v) << endl;
            break;
		//write out the list
        case 'w':
            cout << list1 << endl;
            break;
		//displays menu
        case 'h':
            showmenu(); 
            break; 
		//default
        default:
            break; 
        }
    }
}

//framework for the program
void showmenu()
{
    cout << " This program responds to the commands the user enters to manipulate\n";
    cout << " an ordered list of integers, which is initially empty. In the following \n";
    cout << " commands, k1 is the position in the list, and v is an integer.\n";
    cout << endl;	
    cout << "	 e -- Re-initialize the list to be empty.\n";
    cout << "    i v -- Insert the value v into the list.\n";
    cout << "    r v -- Remove the value v from the list.\n";
    cout << "    m -- Is the list empty?\n";
    cout << "    l -- Report the length of the list.\n";
    cout << "    p v -- Is the value v present in the list?\n";
    cout << "    k k1 -- Report the k1th value in the list.\n";
    cout << "    w -- Write out the list.\n";
    cout << "    h -- See this menu.\n";
    cout << "    q -- Quit.\n";
    cout << endl
	<< endl;
}
