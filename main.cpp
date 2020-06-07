#include <iostream>
#include <algorithm>
using namespace std;

void nojam1920(){
  int N,M;
  cin >> N ;
  int A[N];
  for( int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A,A+N);
  cin >> M ;
  int B[M];
  for (int i=0;i<M;i++){
    cin >> B[i];
  }
  int start, end, mid;
  bool ThereExist;
  for(int i=0;i<M;i++){
    start=0;
    end= N-1;
    mid= (start+end)/2;
    ThereExist =false;
    for (;end-start>=0;){
      if(A[mid]==B[i]){
        ThereExist=true;
        break;
      }
      if(A[mid]>B[i]){
        end=mid-1;
      }
      if(A[mid]<B[i]){
        start=mid+1;
      }
      mid= (start+end)/2;
    }
    if(ThereExist){
      cout << "1"<<"\n";
    }
    if(!ThereExist){
      cout << "0"<<"\n";
    }
  }
}

int main(){
  nojam1920();
}