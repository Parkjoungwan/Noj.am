#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nojam10815(){
  int N,M;
  cin >>N;
  int* sang=new int[N];
  for(int i=0;i<N;i++){
    cin >> sang[i];
  }
  sort(sang,sang+N);
  cin >> M;
  int* nosang=new int[M];
  for(int i=0;i<M;i++){
    cin >> nosang[i];
  }
  int target;
  int check=0;
  for (int i=0;i<M;i++){
    target=nosang[i];
    check=0;
    int end=N-1,start=0;
    int mid = (end-start)/2;
    for(;end-start>=0;){
      if(sang[mid]==target){
        nosang[i]=1;
        check=1;
        break;
      }else if(sang[mid]<=target){
        start=mid+1;
      }else{
        end=mid-1;
      }
      mid=(end+start)/2;
    }
    if(check!=1){
      nosang[i]=0;
    }
  }

  for(int i=0;i<M;i++){
    cout << nosang[i]<<" ";
  }
}

int main() {
 nojam10815();
}
