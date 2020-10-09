#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <sstream>
#include <algorithm>
#include <locale>
#include <string>
#include <map>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;


bool flag = false ;

class Node {

    private:
    int n ; 
    vector<int> key;
    vector<int> left;
    vector<int> right;  

    public:
      void read(){
          cin>>n;
          if(n == 0) {flag = true;cout<<"CORRECT"<<endl; return ;}
          key.resize(n);
          left.resize(n);
          right.resize(n);

          for(int i=0;i<n;i++)cin>> key[i]>>left[i]>>right[i];
      }


      bool isBST(int index){

          static int prev = 0;
          if(index != -1){
              if(!isBST(left[index]))return false ;
              if(prev != 0 && key[index]<= prev)return false;
              prev = key[index];

              return isBST(right[index]);
          }
          return true;
      }

};

int main(){

    Node node;
    node.read();

    if(flag)return 0;

    if(node.isBST(0)){
        cout<<"CORRECT"<<endl;
    }else cout<<"INCORRECT"<<endl;
    return 0;
}
