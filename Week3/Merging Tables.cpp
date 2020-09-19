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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;


vi rows;

int maximumSize = 0;
class UnionFind {
	private: vi p, rank;
	public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] >= rank[y]) p[y] = x, rows[x-1] += rows[y-1],cout<< (rows[x-1]> maximumSize ? rows[x-1] : maximumSize)<<endl, maximumSize = max(maximumSize,rows[x-1]);
			else {
				p[x] = y;
                rows[y-1] += rows[x-1]; 
                cout<<(rows[y-1] > maximumSize ? rows[y-1] : maximumSize)<<endl;
                maximumSize = max(maximumSize,rows[y-1]); 
			}
} } };

int main(){
   

   int n,m;
   cin>>n>>m;

   
   for(int i=0;i<n;i++){
       int num;
       cin>>num;
       maximumSize = max(maximumSize,num);
       rows.push_back(num);
   }

   UnionFind uf(n+1);

   for(int i=0;i<m;i++){
       int source, destination;
       cin>>source>>destination;

       if(!uf.isSameSet(source,destination)){
           uf.unionSet(source,destination);
       }else {
           cout<<maximumSize<<endl;
       }
   }
    return 0;
}
