#include<iostream>

#include "sort.h"

#include "sort.cpp"

#include <cstdlib>

#include<time.h>

using namespace std;

int main() {

  const int size = 5000;
  int merge[size];
  int quick[size];
  int insert[size];
  int heap[size];

  sort q, i, m, h;

  int val;
  char ch;
  int seed;

  cout << "Enter the number of values to generate and sort, between 1 and 5000: ";
  cin >> val;
  cout << "Enter the integer seed value: ";
  cin >> seed;
  srand(seed);

  for (int j = 0; j < val; j++) {
    merge[j] = (rand() % 5000) + 1;
    quick[j] = merge[j];
    insert[j] = merge[j];
  }

  m.mergeSort(merge, 0, val);
  q.quickSort(quick, 0, val);
  i.insertionSort(insert, val);
  cout << "Print the values: ";
  cin >> ch;
  for (int i = (val - 2) / 2; i >= 0; --i) {
    h.reheap_down(heap, i, val - 1);
  }
  for (int i = val - 1; i > 0; --i) {
    swap(heap[0], heap[i]);
    l.reheap_down(heap, 0, i - 1);
  }
  if (ch == 'y') {
    cout << "Insertion Sort- " << endl;
    for (int j = 1; j <= val; j++) {
      cout << insert[j] << " ";
    }

    cout << endl << cout << "Merge Sort-" << endl;
    for (int j = 1; j <= val; j++) {
      cout << merge[j] << " ";
    }

    cout << endl << " Quick Sort-" << endl;
    for (int j = 1; j <= val; j++) {
      cout << quick[j] << " ";
    }
  }

  cout << endl;
  cout << "Count Insertion Sort = " << i.size() << endl;
  cout << "Count Merge Sort = " << m.size() << endl;
  cout << "Count Quick Sort = " << q.size() << endl;
  cout << "Count Heap Sort = " << h.size() << endl;

  return 0;

}
