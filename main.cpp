#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nojam11053(){
  int N;
  int Mp[1010];
  int A[1010];
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> A[i];
  }
  int max=0;
  for(int i=1;i<=N;i++){
    int min = 0;
    for(int j=0;j<i;j++){
      if(A[i]>A[j]){
        if(min<Mp[j]) min = Mp[j];
      }
    }
    Mp[i] = min +1;
    if(max < Mp[i]){
      max = Mp[i];
    }
  }
  cout << max;
}


int main() {
  nojam11053();
}