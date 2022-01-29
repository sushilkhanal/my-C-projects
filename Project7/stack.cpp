#include <iostream>
#include "stack.h"

using namespace std;

//destructor
stack::~stack()
{
    int y;
    while (!is_Empty()) {
        y = pop();
    }
}

//Returns TRUE if the item is "int", FALSE otherwise
bool stack::is_InputValid(item a)
{
    if (a > 0 || a <= 0) {
        return true;
    }
    else {
        return false;
    }
}

//The item entry has been pushed onto the Stack.
void stack::push(item entry)
{
    if (used == CAPACITY - 1) {
        cout << "Stack overflow.\n";
    }
    else {
        arr[used] = entry;
        used++;
    }
}

//The Stack's top item has been popped and returned.
stack::item stack::pop()
{
    int top;
    if (is_Empty()) {
        cout << "Empty stack.\n";
    }
    else {
        --used;
        top = arr[used];
    }
    return top;
}

//The prime factor of the item has been pushed onto the stack
void stack::prime_factor(item num)
{
    for (int i = 2; num != 1; ++i) {
        while ((num % i) == 0) {
            push(i);
            num = num / i;
        }
    }
}

//The contents of the stack have been written to the output stream out_s
ostream& operator<<(std::ostream& out_s, stack& s)
{
    while (s.is_Empty() != true) {
        if (s.size_t() > 1) {
            out_s << s.pop() << " x ";
        }
        else {
            out_s << s.pop();
        }
    }
    return out_s;
}
