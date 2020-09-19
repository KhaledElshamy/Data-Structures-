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


int main()
{
	string str1;
	
    cin>>str1;
    int index = 0 ;

    int firstUnMatchedIndex ;
    stack<char> s;
    while (index < str1.length())
    {
        /* code */
        if(str1.empty()){cout<<0<<endl;break;}
        else {

            if(str1[index] == '(' || str1[index] == '[' || str1[index]== '{'){
                if(s.empty())firstUnMatchedIndex = index+1;
                s.push(str1[index]);
            }
            else {
                if((str1[index]==']'||str1[index]=='}'||str1[index]==')')){
                    if(s.empty()){
                        cout<<index+1<<endl;
                        return 0;
                    }else {
                        char top= s.top();
                        s.pop();
                        if(( top =='[' && str1[index]!=']')||( top=='{' && str1[index]!='}')||( top=='(' && str1[index]!=')')){
                            cout<<index+1<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
        index++;
    }

    if(s.empty())cout<<"Success"<<endl;
    else cout<<firstUnMatchedIndex<<endl;
    return 0;
}
