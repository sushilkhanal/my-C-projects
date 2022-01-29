#include <iostream>
#ifndef LIST_H
#define LIST_H

using namespace std;

//list is the name of the class
class list
{
	public:
		//definatin of data type like int, char etc(here integer)
		typedef int item;    // what can go in a list
		
		//constructor 
		list(){ first=NULL;};//inline 
		//post-condition: The list has been initialized as an empty list
		
		//destructor
		~list();
		
		//modification member fucntion
		void insert(const item& entry);
		//pre-condition: The list does not currently contains the value entry
		//post-condition: entry has been inserted in the position appropriate to its value
		
		void remove(item target);
		//pre-condition: The list contains the value target
		//post-condition: target has been removed from the list 
		
		item make_empty();
		//post-condition: The list has been reinitialized to be empty
		
		//constant member function
		item length();
		//post-condition: The returned value is the length of the list
		
		bool isEmpty() const{return first==NULL;}//inline 
		//post-condition: If the invoking list is empty, return true else false
		
		bool isPresent(const item& target);
		//post-condition: if target is present, return true else false 
		
		item kth(item target);
		//pre-condition: The list is not empty and 1<= target <= length().
		//post-condition: The kth element in the list is returned 
		
		//friend fucntion
		friend std::ostream& operator << (std::ostream& out_s, const list& list1);
	//post-condition: The contents of the list1 have been written to the output stream out_s
		
	private:
	//private data members 
		struct Node
		{
			item data;
			Node* next;
		};
		Node* first;
		
		//Private Function
		//allocates, initializes and returns the address of the new node
		Node* get_node(const item entry, Node* p);
};
#endif
