#include <iostream>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i=a; i<b; i++)

using namespace std;

void siftup(int * x, int value, int n) {
  
  x[n] = value;
  int parent = n/2;

  while (n/2>0 && x[n/2] > value ) {
    int tmp = x[n];
    x[n] = x[n/2];
    x[n/2] = tmp;
    n = n/2;
  }

};


void siftdown(int * x, int position) {
  if (position > 0) {
    x[1] = x[position];
    int parent = 1;
    int child1 = parent * 2;

    while (child1 < position && x[child1] < x[parent]) {
      if (child1 + 1 < position) {
	if (x[child1+1] < x[child1]) {
	  child1 ++;
	}
      }

      int tmp = x[parent];
      x[parent] = x[child1];
      x[child1] = tmp;
      
      parent = child1;
      child1 = parent * 2 ;
    }
  }
};

void display(int * heap, int n) {
  FOR(i, 1, n) {
    cout << heap[i] << ' ' ;
  }
  cout << endl;
};

int main() {

  int heap [100];

  // Any array with less than 100 elements:
  int elements [10] = {34,56,78,123,89,12,43,85,3, 97};
  heap[0]= 0;

  FOR(i, 1, 11) {
    siftup(heap, elements[i-1], i);
  }

  display(heap, 11);

  FOR(i, 1, 11) {
    cout << heap[1] << ' ' ;
    siftdown(heap, 11 - i);
  }
  cout << endl;
  
  return 0;
}
