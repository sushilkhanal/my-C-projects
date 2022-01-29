#include <iostream>
#include <fstream>
#include <cstdlib>
#include "merge.h"
#include "merge.cpp"

using namespace std;

void input_file(ifstream &infile);
void read_file(ifstream& infile, merge& list);

int main()
{
	merge list1,list2,list;
	
	ifstream infile;
	input_file(infile);
	read_file(infile,list1);
	cout<<"There are "<<list1.length()<<" values in the first list:\n";
	cout<<endl<<list1<<endl<<endl;
	infile.close();
	
	input_file(infile);
	read_file(infile,list2);
	cout<<"There are "<<list2.length()<<" values in the second list:\n";
	cout<<endl<<list2<<endl<<endl;
	infile.close();
	cout<<endl;
	
	list.merge_list(list1,list2);
	cout<<"There are "<<list.length()<<" values in the merge list:\n";
	cout<<endl<<list<<endl<<endl;
	
	return 0;
}

void input_file(ifstream& infile)
{
	const int NAMESIZE = 20;
	char input_filename[NAMESIZE +1];
	cout<<"Enter the name of the input filename: ";
	cin>>input_filename;
	infile.open(input_filename);
	if(!infile)
	{
		cout<<"Cannot read the input filename.\n";
		return;
	}
}

void read_file(ifstream& infile, merge& list)
{
	int x;
	while(infile>>x)
	{
		list.insert(x);
	}
}