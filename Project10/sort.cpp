#include <iostream>

#include "sort.h"

using namespace std;

void sort::insertionSort(int ary[], int high) {
  int val;
  int i, j;

  for (i = 1; i < high; i++) {
    val = ary[i];
    j = i;
    count++;
    while (j >= 0 && ary[j] > ary[i - 1]) {
      exchange(ary[j], ary[j - 1]);
      j--;
      count++;
    }
    ary[j + 1] = val;
  }
}

void sort::merge(int a[], int low, int mid, int high) {
  int N;
  int b[N]; //local copy
  int i1, i2, index;
  for (index = low; index <= high; index++) {
    count++;
    b[index] = a[index];
    i1 = low;
    i2 = mid + 1;
    index = low;

    while (i1 <= mid && i2 <= high) {
      count++;
      if (b[i1] < b[i2]) {
        a[index] = b[i1];
        i1++;
      } else {
        a[index] = b[i2];
        i2++;

      }
      index++;
    }

    while (i1 <= mid) {
      count++;
      a[index++] = b[i1++];
    }

    while (i2 <= high) {
      count++;
      a[index++] = b[i2++];
    }
  }
}

void sort::mergeSort(int a[], int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

void sort::partition(int a[], int low, int high, int pivot, int & i, int & j) {
  int lastS1 = low - 1;
  int firstU = low;
  int firstS3 = high + 1;

  while (firstU < firstS3) {
    count++;
    if (a[firstU] < pivot) {
      lastS1++;
      exchange(a[lastS1], a[firstU]);
      firstU++;
    } else if (a[firstU] == pivot) {
      firstU++;
    } else if (a[firstU] > pivot) {
      firstS3--;
      exchange(a[firstU], a[firstS3]);
    }
  }
}

void sort::quickSort(int a[], int low, int high) {
  int pivot;
  int lastS1, firstS3;

  if (low < high) {
    pivot = a[low];
    partition(a, low, high, pivot, lastS1, firstS3);
    quickSort(a, low, lastS1);
    quickSort(a, firstS3, high);
  }

}

void sort::exchange(int & i, int & j) {
  int temp = i;
  i = j;
  j = temp;
}

void reheap_down(Item[a], int parent, int last) {
  int max_child;
  bool done = false;
  while (2 * parent + 1 <= last && !done) {
    max_child = 2 * parent + 1
    if (max_child <= last &&
      a[max_child + 1] > a[max_chid])
      ++max_child;
    if (a[max_child] > a[parent]) {
      exchange(a[parent], a[max_child]);
      parent = max_child;
    } else

  }
}
