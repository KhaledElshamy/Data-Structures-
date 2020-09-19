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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

class StackWithMax 
{ 
    // main stack 
    stack<int> mainStack; 
  
    // stack to keep track of max element 
    stack<int> trackStack; 
  
public: 
    void push(int x) 
    { 
        mainStack.push(x); 
        if (mainStack.size() == 1) 
        { 
            trackStack.push(x); 
            return; 
        } 

        if (x > trackStack.top()) 
            trackStack.push(x); 
        else
            trackStack.push(trackStack.top()); 
    } 
  
    int getMax() 
    { 
        return trackStack.top(); 
    } 
  
    int pop() 
    { 
        mainStack.pop(); 
        trackStack.pop(); 
    } 
}; 

int main(){

    string s;
    int num;

    int numOfTestCases;
    cin>>numOfTestCases;

    StackWithMax Stack;
    while (numOfTestCases--)
    {
        /* code */
        cin>>s;

        if(s[0] == 'p' && s[1]== 'u'){
            cin>> num;
            Stack.push(num);
        }else {
            if(s == "pop")Stack.pop();
            else cout<<Stack.getMax()<<endl;
        }
    }
    
    return 0;
}
