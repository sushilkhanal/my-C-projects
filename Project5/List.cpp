#include <iostream>
#include <cassert>
#include <cstdlib>
#include "List.h"

using namespace std;

//destructor
list::~list()
{
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

//this function returns the length of the call list
int list::length()
{
    Node* g;
    int count = 0;
    g = first;
    while (g != NULL) {
        ++count;
        g = g->next;
    }
    return count;
}

//this function empties the call list
int list::a_empty()
{
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

//this function returns true if value is present in the call list, else false
bool list::isPresent(const item& target)
{
    Node* prev;
    prev = first;
    while (prev != NULL && prev->data != target) {
        prev = prev->next;
        return (prev != NULL);
    }
}

//this function returns the kth value
list::item list::kth(item target)
{
    Node* prev;
    prev = first;
    for (int i = 0; i < target; ++i) {
        prev = prev->next;
    }
    return (prev->data);
}

//this function inserts the new element
void list::insert(const item& entry)
{
    Node* prev;
    assert(!isPresent(entry));
    if (first == NULL || entry < first->data) {
        first = get_node(entry, first);
    }
    else {
        prev = first;
        while (prev->next != NULL && prev->next->data < entry)
            prev = prev->next;
        prev->next = get_node(entry, prev->next);
    }
}

//this function removes the target value
void list::remove(item target)
{
    Node* prev;
    assert(isPresent(target));
    prev = first;
    if (first->data == target) {
        first = first->next;
        delete prev;
    }
    else {
        Node* temp;
        while (prev->next->data != target)
            prev = prev->next;
        temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
}

//this function returns the address of the new node
list::Node* list::get_node(const item entry, Node* g)
{
    Node* temp;
    temp = new Node;
    temp->data = entry;
    temp->next = g;
    return temp;
}

//this function writes out the items to the output stream
ostream& operator<<(ostream& out_s, const list& list1)
{
    list::Node* g;
    if (list1.first == NULL) {
        cout << "  There are no values currently in the list.";
    }
    else {
        g = list1.first;
        cout << "  The List is: ";
        cout << " < ";
        while (g != NULL) {
            out_s << g->data << " ";
            g = g->next;
        }
        cout << " >";
        return out_s;
    }
}
