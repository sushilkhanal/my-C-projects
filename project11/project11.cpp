#include<iostream>
#include<iomanip>
#include<fstream>
#include"tree.h"
#include "tree.cpp"
using namespace std;

const int maxsize=10;

void menu()
{
    cout<<"This program responds to the following commands to "<<endl;
    cout<<"manipulate an inventory, which is initially empty."<<endl;
    cout<<"The command prompt for additional information, if necessary."<<endl;
    cout<<endl;
    cout<<"  f -- Read an inventory from a file."<<endl;
    cout<<"  i -- Insert an item into the inventory."<<endl;
    cout<<"  r -- Remove an item from the inventory."<<endl;
    cout<<"  e -- Report if the inventory is empty."<<endl;
    cout<<"  a -- Report an item's information."<<endl;
    cout<<"  v -- Report the inventory's total value."<<endl;
    cout<<"  p -- Print the inventory to the terminal."<<endl;
    cout<<"  h -- See this menu."<<endl;
    cout<<"  q -- Quit the program."<<endl;

}

void filename(ifstream &infile, tree t)
{
    int number, quantity;
    char name[maxsize];
    char choice;
    double price;
    char file[maxsize];
    cout<<"Enter inventory file name: ";
    cin>>file;
    infile.open(file);
    if(!infile)
    {
        cout<<"cannot open";
        return;
    }
    while(!infile.eof())
    {
        infile>>number;
        infile>>name;
        infile>>quantity;
        infile>>price;
        t.insert(number, name, quantity, price);
    }
    infile.clear();
    infile.close();
}

void inse_rt(tree t)
{
    int item, qty;
    char nam[maxsize];
    double pc;
    cout<<"Enter the descriptioon of an item: \n";
    cout<<"Number: ";
    cin>>item;
    cout<<"Name: ";
    cin>>nam;
    cout<<"Quantity: ";
    cin>>qty;
    cout<<"Price: ";
    cin>>pc;
    t.insert(item, nam, qty, pc);
}

int main()
{
    tree t;
    int number, quantity;
    char choice;
    double price;
    ifstream infile;
    menu();
    while(choice != 'q')
    {
        cout<<"-->";
        cin>>choice;
        switch(choice)
        {

            case 'f' : filename(infile, t);
                       break;

           case 'i' : inse_rt(t);
                      break;

           case 'p' : cout<<t;
                      break;

           case 'h' : menu();
                    break;

            case 'q':break;

            case 'e' : if(t.isEmpty()==true)
                       cout<<"The list is empty.\n";
                     else
                       cout<<"The list is not empty.\n";
                     break;

            case 'r' :cout<<"remove the item from inventory: ";
                    cin>>number;
                    t.remove(number);
                    break;

            case 'a' : cout<<"Report the item from an inventory: ";
                        cin>>number;
                        (t.report_a(number));
                        break;

            case 'v' : cout<<"total value of the inventory: ";
                      (t.total());
                       break;

            default :cout<<"Invalid; enter another case"<<endl;

        }

    }
}
