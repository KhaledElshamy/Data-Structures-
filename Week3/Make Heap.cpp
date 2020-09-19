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

typedef pair<int,int> ii;

  vector<ii> swaps;
  vector<int> arr;

  int Parent_idx(int child_idx) {
	  return int((child_idx + 1) / 2);
  }

  int left_child_idx(int parent_idx) {
	  return 2 * parent_idx + 1;
  }

  int right_child_idx(int parent_idx) {
	  return 2 * parent_idx + 2;
  }

  void siftDown(int index){

      int leftChildIndex = left_child_idx(index);
      int rightChildIndex = right_child_idx(index);

      int minIndex = index;
      if(leftChildIndex < arr.size() && arr[leftChildIndex] < arr[index]) minIndex = leftChildIndex;

      if(rightChildIndex < arr.size() && arr[rightChildIndex] < arr[minIndex]) minIndex = rightChildIndex;

      if(index != minIndex){
          swap(arr[index], arr[minIndex]);
          swaps.push_back(make_pair(index,minIndex));
          siftDown(minIndex);
      }
  }


  void generateSwaps(){
      swaps.clear();
      for(int i= int(arr.size() / 2);i>=0;i-- )siftDown(i);
  }

int main(){

    
   int n;
   scanf("%d",&n);

   for(int i=0;i<n;i++){
       int num ;
       cin>> num;
       arr.push_back(num);
   }

   generateSwaps();

   cout<<swaps.size()<<endl;
   for(int i= 0;i<(int)swaps.size();i++){
       cout<< swaps[i].first<<" "<<swaps[i].second<<endl;
   }

    return 0;
}
