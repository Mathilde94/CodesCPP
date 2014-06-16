#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define NHASH 29989
#define MULT 31

using namespace std;

struct node {

  char * word;
  int count;
  node * next;

};

node * construct_node(char * word, node * next) {
  node * new_node = (node *)malloc(sizeof(node));
  new_node->count = 1;
  new_node->next = next;
  new_node->word = (char *)malloc(sizeof(char) * (strlen(word) + 1));
  strcpy(new_node->word, word);
  return new_node;
}; 

unsigned int compute_hash(char * word) {
  unsigned int h = 0;
  char * p = word;
  while (*p) {
    h = MULT * h + *p;
    p ++;
  }

  return h % NHASH;
};

node * BIN [NHASH];

int main (int argc, char * argv []) {
  
  ifstream file;
  file.open(argv[1]);
  
  for (int i =0 ; i < NHASH; i++) {
    BIN[i] = NULL;
  }

  string word;
  while (file >> word) {
    char * w =&word[0];
    node * p = BIN[compute_hash(w)];
    bool found = false;
    while (p) {
      if (strcmp(p->word, w) == 0) {
	p->count ++;
	found = true;
	break;
      }
      p = p->next;
    }
    if (! found) {
      node * new_node = construct_node(w, BIN[compute_hash(w)]);
      BIN[compute_hash(w)] = new_node;
    }
  } 

  cout << "END!" << endl;
  file.close();

  for (int j=0; j < NHASH; j++) {
    node * p = BIN[j];
    bool found = false;
    if (p) {
      cout << j << "  ";
      while (p) {
	cout<<  p->word << ": "<< p->count << " ";
	p = p->next;
      }
      cout << endl;
    }
  }
  return 0;
}
