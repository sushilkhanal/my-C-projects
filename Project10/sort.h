#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
class sort
{
	private:

	int count;


	public:

	sort()
	{
		count =0;
	}

	int size()
	{
		return count;
	}

	void insertionSort(int[], int);
	void merge(int[], int, int, int);
	void mergeSort(int[], int, int);
	void quickSort (int[], int, int );
	void partition (int[], int, int, int, int&, int&);
	void exchange(int&, int&);
	void reheap_down(Item[], int, int)



};




#endif // SORT_H_INCLUDED
