#include <iostream>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

class Hanoi{
public:
  int n;
  vector<int> tower [3];
  
  Hanoi(int number){
    n=number;
    FOR(i,0,n){
      tower[0].push_back(n-i-1);
    }
  }

  void display(){
    FOR(i,0,3){
      cout << "Tower "<<i<<": ";
      FOR(j,0,tower[i].size()){
        cout << tower[i][j]<<' ';
      }
      cout << endl;
    }
  }

  void move(int k,int from, int to){
    tower[from].pop_back();
    tower[to].push_back(k);
    cout << "Moving "<<k<<" from "<<from<<" to "<<to<<endl;
  }

  void recursion(int k,int from, int to){
    if (k==0){
      move(k,from,to);
    }
    else{
      int other = 3-from-to;
      recursion(k-1,from ,other);
      move(k,from,to);
      recursion(k-1, other, to);
    }
  }
  
};


int main(int argc, char ** argv){
  cout << "Choose a number between 1 and 10:"<<endl;
  int n = 0; //(int) *argv[1] - 48;
  cin >> n ;
  cout <<"Hanoi for " <<n <<" elements:"<<endl;
  Hanoi hanoi = Hanoi(n);
  hanoi.display();
  hanoi.recursion(n-1,0,1);
  hanoi.display();
  return 0;
}
