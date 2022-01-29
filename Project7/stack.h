#include <iostream>
#ifndef STACK_H
#define STACK_H

using namespace std;

class stack
{
public:
    // defination of data types like int, char, etc(integer in this case)
    typedef int item; // enters the stack
    static const item CAPACITY = 100; // maximum size of the stack

    // constructor
    stack()
    {
        used = 0;
    } // inline
    // Postcondition: The stack has been initialized as an empty stack.

    // destructor
    ~stack();

    // modification member function
    void push(item entry);
    // Postcondition: The (item entry) has been pushed into the stack.

    item pop();
    // Precondition: size_t() > 0; i.e the stack is not empty.
    // Postcondition: The stack's top item has been popped and returned.

    // precondition: The (item integer) lies between negative infinity to positive infinity,
    void prime_factor(item integer);
    // i.e, it shouldn't be a character
    // postcondition: The prime factor of the item has been pushed onto the stack

    // boolean function
    bool is_Empty()
    {
        return used == 0;
    }
    // Postcondition: Returns true if the stack is empty, else FALSE

    bool is_InputValid(item a);
    // Postcondition: Returns true if the item is int,else FALSE

    // constant member function
    item size_t() const
    {
        return used;
    } // Inline
    // postcondition: Returns the total size of the stack used

    // friend function
    friend std::ostream& operator<<(std::ostream& out_s, stack& s);
    // post-condition: The contents of the stack have been printed as an output
    // stream out_s

private:
    // private data members
    item used;
    // capacity of the array to store data
    item arr[CAPACITY];
};
#endif
