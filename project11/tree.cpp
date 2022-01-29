#include<iostream>
#include<fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "tree.h"

using namespace std;

void tree::destroy(Node*p)
{
    if(p!=NULL)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

//if the value is present or not
bool tree::isPresent(int target)
{
    Node*p=root;
    while(true)
    {
        if(p==NULL)
            return false;
        else if(target < p->id)
            p=p->left;
        else if(target==p->id)
            return true;
        else//target>p->data
            p=p->right;
    }
}

void tree::insert(int item, char nam[], int qty, double pc)
{
    help_insert(root, item, nam, qty, pc);
}

 void tree::help_insert(Node *&t, int item, char nam[], int qty, double pc)
    {
        if(t==NULL)
        {
            t =new Node;
            t->id=item;
            strcpy(t->name, nam);
            t->quantity=qty;
            t->price=pc;
            t->left= NULL;
            t->right=NULL;
        }
        else if(item <t->id)
            help_insert(t->left, item,nam,qty,pc);
        else //entry>t->data
            help_insert(t->right,item,nam,qty,pc);
}

std::ostream& operator <<(std::ostream &out_s, tree &t)
{
    t.print(out_s,t.root);
    return out_s;
}

void tree::print(ostream &out_s, Node*p)
{
    cout<<"Number";
    cout<<setw(10)<<"name";
    cout<<setw(10)<<"quantity";
    cout<<setw(10)<<"price\n";
    cout<<"-----------------------------------\n";
    if(p!=NULL)
    {
        print(out_s,p->left);
        cout<<p->id<<" ";
        cout<<p->name<<" ";
        cout<<p->quantity<<" ";
        cout<<p->price<<" ";
        print(out_s,p->right);
    }
    cout<<"------------------------------------\n";
}

    //to remove the value from the inventory
void tree::remove(int target)
{
    help_remove(root,target);
}

void tree::help_remove(Node *&t, int target)
{
    if(t->id==target)
        remove_node(t);
    else if(target<t->id)
        help_remove(t->left, target);
    else //target>t->data
        help_remove(t->right, target);
}


void tree::report_a(int target )
{
    Node*t=root;
    while(t->id!=target)
    {
        if(target<t->id)
            t=t->left;
        else
            t=t->right;
    }
    cout<<"  Name:       "<<t->name;
    cout<<"  Quantity:   "<<t->quantity;
    cout<<"  Price:      "<<t->price;
}

int tree::total()
{
     return total_v(root);
}

int tree::total_v(Node*&t)
{
    while(t->id!=NULL)
    {
        return ((t->quantity)*(t->price)+total_v(t->left)+total_v(t->right));
    }
}


//to remove value from inventory
void tree::remove_node(Node *&t)
{
    Node *ptr;
    Node *back;

    if(t->left==NULL && t->right==NULL) //1
    {
        delete t;
        t=NULL;
    }
    else if(t->left==NULL)//2a case
    {
        ptr=t;
        t=t->right;
        delete ptr;
    }
    else if (t->right ==NULL)//2b case
    {
        ptr=t;
        t=t->left;
        delete ptr;
    }
    else //3,we find the leftmost node in the right subtree
    {
        back=t;
        ptr=ptr->left;
    }
    t->id=ptr->id;
    if(back==t)
        remove_node(back->right);
    else
        remove_node(back->left);
}


