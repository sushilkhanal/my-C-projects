#include <iostream>
#include <cstdlib>
#include <cassert>
#include "merge.h"

using namespace std;

merge::~merge()
{
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

void merge::make_empty()
{
    Node* temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        delete temp;
    }
}

int merge::length()
{
    item count = 1;
    Node* temp;
    temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void merge::insert(item entry)
{
    Node* prev;
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

void merge::merge_list(const merge& list1, const merge& list2)
{
    Node* last;
    Node* n1;
    Node* n2;
    n1 = list1.first;
    n2 = list2.first;
    if (n1 != NULL && n2 != NULL) {
        if (n1->data < n2->data) {
            first = get_node(n1->data, NULL);
            n1 = n1->next;
        }
        else if (n2->data < n1->data) {
            first = get_node(n2->data, NULL);
            n2 = n2->next;
        }
        else {
            first = get_node(n1->data, NULL);
            n1 = n1->next;
            n2 = n2->next;
        }
        last = first;
    }
    while (n1 != NULL && n2 != NULL) {
        if (n1->data < n2->data) {
            last->next = get_node(n1->data, NULL);
            n1 = n1->next;
        }
        else if (n2->data < n1->data) {
            last->next = get_node(n2->data, NULL);
            n2 = n2->next;
        }
        else {
            last->next = get_node(n2->data, NULL);
            n1 = n1->next;
            n2 = n2->next;
        }
        last = last->next;
    }
    while (n1 != NULL) {
        last->next = get_node(n1->data, NULL);
        n1 = n1->next;
        last = last->next;
    }
    while (n2 != NULL) {
        last->next = get_node(n2->data, NULL);
        n2 = n2->next;
        last = last->next;
    }
}

ostream& operator<<(ostream& out_s, const merge& list)
{
    merge::Node* n;
    n = list.first;
    cout << n->data << " ";
    while (n->next != NULL) {
        n = n->next;
        out_s << n->data << " ";
    }
    return out_s;
}

merge::Node* merge::get_node(const item& entry, Node* n)
{
    Node* temp;
    temp = new Node;
    temp->data = entry;
    temp->next = n;
    return temp;
}
