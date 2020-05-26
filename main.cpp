#include <iostream>
#include <vector>
using namespace std;

void nojam9465(){
  int T;
  cin >> T;
  int result[T];
  for(int t=0;t<T;t++){
    int N;
    cin >> N;
    int S[2][N+2];
    S[0][0]=-1;
    S[1][0]=-1;
    S[0][N+1]=-1;
    S[1][N+1]=-1;
    for(int i=0;i<2;i++){
      for(int j=1;j<=N;j++){
        cin >> S[i][j];
      }
    }
    int sum=0;
    while(1){
      int max=-1;
      int target1,target2;
      for(int i=0;i<2;i++){
        for(int j=1;j<=N;j++){
          if(S[i][j]>max) {
            max=S[i][j];
            target1=i;
            target2=j;
          }
        }
      }
      if(max==-1) break;
      sum+=S[target1][target2];
      S[target1][target2]=-1;
      if(target1==0){
        S[target1+1][target2]=-1;
        S[target1][target2+1]=-1;
        S[target1][target2-1]=-1;
      }else{
        S[target1-1][target2]=-1;
        S[target1][target2+1]=-1;
        S[target1][target2-1]=-1;
      }
    }
    result[t]= sum;
  }  
  for(int t=0;t<T;t++){
    cout << result[t]<<endl;
  }
}

int main() {
  nojam9465();
}