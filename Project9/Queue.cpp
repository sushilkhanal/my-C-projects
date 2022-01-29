#include<iostream>
#include<cstdlib>
#include "Queue.h"
using namespace std;
Queue::Queue()
		{
			f = 0; //front of the queue
			r = CAPACITY-1;  //rear of the queue
			count = 0;
		};
void Queue::enqueue(Item entry)
{
    r = next_index(r);
    data[r] = entry;
    ++count;
}
Queue::Item Queue::dequeue()
{
    Item dequed;
    dequed=data[f];
    f=next_index(f);
    --count;
    return dequed;
}
ostream& operator <<(ostream& out_s, Queue& q){
Queue::Item it;
int n;
n=q.size();
for(int i=0;i<n;++i){
    it=q.dequeue();
    out_s<<it<<" ";
    q.enqueue(it);
}
return out_s;
}
