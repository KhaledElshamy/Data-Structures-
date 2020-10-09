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


class Node {

    private:
    int n ; 
    vector<int> key;
    vector<int> left;
    vector<int> right;  

    public:
      void read(){
          cin>>n;
          key.resize(n);
          left.resize(n);
          right.resize(n);

          for(int i=0;i<n;i++)cin>> key[i]>>left[i]>>right[i];
      }

      void inOrder(int index){
          if(index != -1){
              inOrder(left[index]);
              cout<<key[index]<<" ";
              inOrder(right[index]);
          }
      }

      void preOrder(int index){
          if(index != -1){
              cout<<key[index]<<" ";
              preOrder(left[index]);
              preOrder(right[index]);
          }
      }

      void postOrder(int index){
          if(index != -1){
              postOrder(left[index]);
              postOrder(right[index]);
              cout<<key[index]<<" ";
          }
      }

};

int main(){

    Node node;
    node.read();

    node.inOrder(0);
    cout<<endl;
    node.preOrder(0);
    cout<<endl;
    node.postOrder(0);
    return 0;
}
