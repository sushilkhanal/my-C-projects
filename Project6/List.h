#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

//class named list
class list {
public:
    //defination of data type
    typedef int item; // what goes in a list

    //constructor
    list() { first = NULL; }; //inline
    //post-condition: The list was set as an empty list

    //destructor
    ~list();

    //modification member function
    void insert(const item& entry);
    //pre-condition: The list does not contain the entry value
    //post-condition: data was entered in the appropriate position

    void remove(item target);
    //pre-condition: The list contains the target value
    //post-condition: target was removed from the list

    item a_empty();
    //post-condition: The list was reinitialized to be empty

    //constant member function
    item length();
    //post-condition: The returned value was the length of the list

    bool bEmpty() const { return first == NULL; } //inline
    //post-condition: If the call list is empty, return true else false

    bool isPresent(const item& target);
    //post-condition: if the target is present, return true else false

    item kth(item target);
    //pre-condition: The list is not empty and 1<= target <= length().
    //post-condition: The kth element in the list has returned

    //friend function
    friend std::ostream& operator<<(std::ostream& out_s, const list& list1);
    //post-condition: The contents of the list were written to the output stream

private:
    //private data members
    struct Node {
        item data;
        Node* next;
    };
    Node* first;

    //Private Function
    //allocates, initializes and returns the address of the new node
    Node* get_node(const item entry, Node* g);
};
#endif
