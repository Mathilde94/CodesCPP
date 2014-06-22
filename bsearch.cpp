#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define FOR(i, a,b) for(int i=a; i< b; i++)

using namespace std;

void insertion_sort(int * t, int n) {
  FOR(i, 1, n) {
    int j = i;
    int tmp = t[i];
    while (j > 0 && t[j-1] > tmp) {
      int tmp_cell = t[j];
      t[j] = t[j-1];
      t[j-1] = tmp_cell;
      j--;
    }
    t[j] = tmp;
  }
}

void display(int * t, int n) {

  FOR(i, 0, n) {
    cout << t[i] << ' ' ;
  }
  cout << endl;

}

bool verification_order(int * t, int n) {
  FOR(i, 1, n) {
    if (t[i] < t[i-1]) {
      return false;
    }
  }
  return true;
}

bool binary_search(int *t, int value, int l, int u) {

  if (l > u) {
    return false;
  }
  if (l==u) {
    if (t[l] == value)
          return true;
    else 
      return false;
  }
  
  int m = (l+u) / 2;
  
  if (t[m] > value) 
    return binary_search(t, value, l, m);
  if (t[m] == value)
    return true;
  else
    return binary_search(t, value, m+1, u);
    

};

bool binary_verification(int * t, int n) {
  FOR(i, 0, n) {
    if (!binary_search(t, t[i], 0, n)) {
      cout << "Opsee..." << t[i] << " was said not to be in the array ..." << endl;
      return false;
    }
  }

  int w [10] = {-12, -6, 0, 2, 17, 24, 56, 68, 92, 100};
  FOR(i, 0, n) {
    if (binary_search(t, w[i], 0, n)) {
      cout << "Opsee..." << w[i] << " was not supposed to be in the initial array..." << endl;
      return false;
    }
  }

  return true;
}

int main (void) {

  int t [10] = {34,12,67,98,43,3,73,90,18,31};
  int n = sizeof(t) / sizeof(int);
  
  insertion_sort(t, n);
  display(t, n);

  bool ordered = verification_order(t, n);
  cout << (ordered ? "Ordered": "Not ordered") << endl;
  if (ordered) {
    cout << (binary_verification(t, n) ? "Binary Search ok" : "Problem in Binary Search") << endl;
  }

  return 0;
}
