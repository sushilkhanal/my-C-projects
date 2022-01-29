#include <iostream>
#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <string.h>
using namespace std;

class tree{
public:
    //constructor
    tree(){root=NULL;}
    //destructor
    ~tree(){destroy(root);}
    //to insert a value
    void insert(int item, char name[], int quantity, double price);
    //to remove the value from the inventory
    void remove(int target);
    int total();
    void report_a(int item );
    //if the item is present or not
    bool isPresent(int target);
    bool isEmpty(){return root==NULL;}
    friend ostream& operator<<(ostream &out_s, tree &t);

private:
    struct Node
    {
        int id;
        char name[10];
        int quantity;
        double price;
        Node*left;
        Node*right;
    };
    Node*root;

    void help_insert(Node *&t, int item, char nam[], int quantity, double price);
    void print(ostream &out_s,Node*p);
    void help_remove(Node *&t, int target);
    void destroy(Node*p);
    int total_v(Node*&t);
    void remove_node(Node *&t);

};



#endif // TREE_H
