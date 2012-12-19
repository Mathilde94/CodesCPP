#include <iostream>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

struct node{
  int value;
  node * next;
};

node * createNode(int n, node * next_node){
  node *a;
  a=(node *)malloc(sizeof(node));
  a->value=n;
  a->next = next_node;
  return a;
}


void displayList(node * begin){
  node *p =begin;
  while (p!=NULL){
    cout << p->value <<' ';
    p=p->next;
  }
  cout << endl;
}

node * createListFromEnd(node * begin, int values [],int n){
  FOR(i,0,n){
    node * a = createNode(values[i],begin);
    begin=a;
  }

  return begin;
}

node * createListFromBeg(node * begin,int values [],int n){
  FOR(i,0,n){
    node * p=begin;
    if (p==NULL){
      node *a= createNode(values[i],NULL);
      begin=a;
    }
    else{
      while (p->next!=NULL){
        p=p->next;
      }
      node * a= createNode(values[i],NULL);
      p->next=a;
    }
  }

  return begin;
}


node * createOrderedList(node * begin,int values [], int n){
  if (begin==NULL){begin= createNode(values[0],NULL);}
  int beg = (begin==NULL)?1:0;
  FOR(i,beg,n){
    if (begin->value > values[i]){
      node * a =createNode(values[i], begin);
      begin=a;
    }
    else{      
      node * p = begin;
      node * q = begin->next;
      while (q!=NULL && !(p->value < values[i] && q->value>values[i]) ){
        q=q->next;
        p=p->next;
      }
      node * a =createNode(values[i],q);
      p->next=a;
    }
  }
  return begin;
}

void insert(node * & begin, int value){
  node * p=begin;
  if (p!=NULL){
    if (begin->value > value){
      node * a = createNode(value,begin);
      begin =a;
    }
    else{
      node * q=begin->next;
      while (q!=NULL && !(p->value< value && q->value> value)){
        q=q->next;
        p=p->next;
      }
      node * a =createNode(value,q);
      p->next=a;
    }
  }
  if (p==NULL){
    node * a =createNode(value,NULL);
    begin=a;
  }
}


node * reverseList(node * begin){
  node * reverse = NULL;
  node * p=begin;

  while (p!=NULL){
    node * next_node = p->next;
    p->next=reverse;
    reverse = p;
    p = next_node;
  }

  return reverse;
}

int main(int argc, char ** argv){
  node * begin=NULL;

  int values [] ={12,3,45,6,23,78,9,2};
  int n = sizeof(values)/sizeof(int);

  displayList(createListFromEnd(NULL,values,n));
  displayList(createListFromBeg(NULL,values,n));
  insert(begin,22);
  insert(begin,45);
  insert(begin,1);
  displayList(begin);
  begin=createOrderedList(begin,values,n);
  displayList(begin);
  insert(begin,56);
  displayList(begin);
  displayList(reverseList(begin));

  return 0;
}
