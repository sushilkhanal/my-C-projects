#include <iostream>
#include <cassert>
#include <cstdlib>
#include "list.h"

using namespace std;

//destructor 
list::~list()
{
	Node*temp;
	while(first!=NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
}

//returns the length of the invoking list
int list::length()
{
	Node*p;
	int count = 0;  
	p=first;
	while(p!=NULL)
	{
		++count;
		p=p->next;
	}
	return count;
}

//make the invoking list empty
int list::make_empty()
{
	Node*temp;
	while(first!=NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
}

//returns true if value is present in the invoking list, else false 
bool list::isPresent(const item& target)
{
	Node* prev;
	prev = first;
	while(prev!=NULL && prev->data != target)
	{
		prev = prev->next;
		return (prev!=NULL);
	}
}

//Returns the kth value from the invoking list 
list::item list::kth(item target)
{
	Node*prev;
	prev = first;
	for(int i=0; i<target; ++i)
	{
		prev=prev->next;
	}
	return (prev->data);
}

//inserts the new element into the invoking list
void list::insert(const item& entry)
{
	Node*prev;
	assert ( ! isPresent(entry) );
	if(first == NULL || entry < first->data)
	{
		first=get_node(entry,first);
	}
	else
	{
		prev = first;
		while(prev->next!= NULL && prev->next->data<entry)
			prev=prev->next;
		prev->next = get_node(entry,prev->next);
	}
}

//Remove the target value from the invoking list 
void list::remove(item target)
{
	Node*prev;
	assert ( isPresent(target) );
	prev=first;
	if(first->data == target)
	{
		first=first->next;
		delete prev;
	}
	else
	{
		Node*temp;
		while(prev->next->data != target)
		prev = prev->next;
		temp = prev->next;
		prev->next = temp->next;
		delete temp;
	}
}

//allocates, initializes and returns the address of the new node
list::Node* list::get_node(const item entry, Node* p)
{
	Node*temp;
	temp = new Node;
	temp->data = entry;
	temp->next = p;
	return temp;
}

//writes out the items of the invoking list to the output stream
ostream& operator << (ostream& out_s, const list& list1)
{
	list::Node*p;
	if(list1.first==NULL)
	{
		cout<<"  There are no values currently in the list.";
	}
	else
	{
		p=list1.first;
		cout<<"  The List is: ";
		cout<<" < ";
		while(p!=NULL)
		{
			out_s<<p->data<<" ";
			p=p->next;
		}
		cout<<" >";
		return out_s;
	}
}
