#include<iostream>
#include<cstdlib>
using namespace std;
class Queue
{
	public:
		typedef int Item;
		static const int CAPACITY = 30;
		//constructor
		Queue();
		bool empty() {return count == 0;}
		int size() {return count;}
		void enqueue(Item entry);
		Item dequeue();
		friend ostream& operator <<(ostream & out_s,Queue& q);
	private:
		Item data[CAPACITY];
		int f;
		int r;
		int count;
		int next_index(int i)
		{
			return (i+1) % CAPACITY;
		}
};
