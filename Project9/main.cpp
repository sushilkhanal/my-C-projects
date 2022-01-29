#include<iostream>
#include<cstdlib>
#include"Queue.h"
#include"Queue.cpp"
using namespace std;
int main ()
{
	int DURATION;
	int ARV_PROB;
	int MAX_TRANS_TIME;
	int LENGTH;
	cout<<"\nEnter these parameters of the simulation: "<<endl;
	cout<<"The number of queue/server pairs: "<<endl;
	cin>>LENGTH;
	cout<<"The probability that a customer arrives in one tick (%) : "<<endl;
	cin>>ARV_PROB;
	cout<<"The maximum duration of a transaction in ticks: "<<endl;
	cin>>MAX_TRANS_TIME;
	cout<<"The duration of the simulation in ticks: "<<endl;
	cin>>DURATION;
	Queue line[LENGTH];
	int trans_time[LENGTH];
	for(int l=0; l<LENGTH; ++l)
	{
		trans_time[l] = 0;
	}
	int count = 0;
	int entrytime;
	int wait_sum = 0;
	int wait = 0;
	int seed;
	int customer = 0;
	int queue = 0;
	cout<<"Enter a random number seed : "<<endl;
	cin>>seed;
	cout<<"\n \n \n";
	srand(seed);
	for(int time=0; time<DURATION; ++time)
	{
		int least =0;
		if(rand()%100 < ARV_PROB)
		{
			int start = 1;
			while (start < LENGTH)
			{
				//getting the line with the smallest size
				if(line[least].size() > line[start].size())
				{
					least = start;
				}
				++start;
			}
			line[least].enqueue(time);
		}
		for (int i = 0;i<LENGTH; ++i)
		{
			if(trans_time[i] == 0)
			{
				if(!line[least].empty())
				{
					entrytime = line[least].dequeue();
					wait_sum += time - entrytime;
					wait = time - entrytime;
					if(wait>queue)
						queue = wait;
					++count;
					trans_time[i] = rand() % MAX_TRANS_TIME + 1;
				}
			}
			else
			--trans_time[i];
			cout<<endl;
	 	}
			cout<<time<<" ";
			for(int j = 0; j<LENGTH; ++j)
			{
				cout<<"\t"<<trans_time[j]<<"\t"<<line[j]<<endl;
			}
		}
	for(int i = 0; i<LENGTH; ++i)
	{
		customer = customer + line[i].size();
	}
	cout<<count<<"customers waited an average of "<<wait_sum/count<<"ticks."<<endl;
	cout<<"The longest time a customer waited was "<<queue<<"ticks."<<endl;
	cout<<customer<<"customers remain in the lines. "<<endl;
	return 0;
}
