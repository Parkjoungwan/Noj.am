#include <iostream>
using namespace std;

void Test(int* arr, int N){
  for(int i=0;i<N;i++){
    cout << arr[i];
  }
}

void nojam2805(){
  int N;
  long long M;
  cin >> N >> M;
  long long* Tree=new long long[N];
  long long High=0;
  for (int i=0;i<N;i++){
    cin >>Tree[i];
    if(Tree[i]>High){
      High=Tree[i];
    }
  }
  long long Low = 1;
  long long result=0;
  while(Low<=High){
    long long mid = (High+Low)/2;
    long long sum=0;
    for(int i=0;i<N;i++){
      if(Tree[i]>mid){
        sum+=Tree[i]-mid;
      }
    }
    if(sum>=M){
      if(result<mid){
        result=mid;
      }
      Low=mid+1;
    }else{
      High=mid-1;
    }
  }
  cout << result;
}

int main(){
  nojam2805();
}