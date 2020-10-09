#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> ii;

#define minimum  (-9223372036854775807 - 1)
#define maximum  9223372036854775807

struct Node {
    int key;
    int left;
    int right;

    Node() : key(0), left(-1), right(-1) {}

    Node(int key_, int left_, int right_){
        key = key_;
        left = left_;
        right = right_;
    }
};


bool isBST(vector<Node>& tree, const int &index, long long minVal, long long maxVal){

    if(index != -1){

        if(tree[index].key < minVal || tree[index].key >= maxVal) return false; 
        return isBST(tree,tree[index].left,minimum,tree[index].key) && isBST(tree,tree[index].right,tree[index].key,maximum);
    }

    return true; 
}

int main(){

    int nodes;
    cin >> nodes;
    
    vector<Node> tree;
    
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }

    if(tree.size() == 0) {
        cout<<"CORRECT"<<endl;
        return 0;
    }
    
    if(isBST(tree,0,minimum,maximum)){ 
        cout<<"CORRECT"<<endl;
    }else cout<<"INCORRECT"<<endl;
    return 0;
}
