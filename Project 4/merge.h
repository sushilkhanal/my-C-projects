#include <iostream>
#ifndef MERGE_H
#define MERGE_H

using namespace std;

class merge {
public:
    typedef int item;
    merge() { first = NULL; } //constructor
    ~merge(); //destructor
    void insert(item entry); //modification member function
    void make_empty(); //This function clears the list.
    void merge_list(const merge& list1, const merge& list2);
    int length(); //constant member function
    friend std::ostream& operator<<(std::ostream& out_s, const merge& list); //friend function
private:
    struct Node {
        item data;
        Node* next;
    };
    Node* first;

    Node* get_node(const item& entry, Node* n);
};
#endif
