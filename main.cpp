#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void nojam7576(){
  int N,M;
  cin >> M >> N ;
  int** toma=new int* [N];
  for (int i=0;i<N;i++){
    toma[i]=new int[M];
  }
  for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >>toma[i][j];
    }
  }
  int day=0;
  int ok;
  while(ok!=N*M){
    ok=0;
    for (int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if (toma[i][j]==1){
          //가장자리가 아닌 경우
          if(i>0&&i<N-1&&j>0&&j<M-1){
            toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
            toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
            toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
            toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
          }
          //가장자리(윗줄)인 경우
          else if(i==0){
            if(j==0){
              toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
              toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
            }else if(j==M-1){
              toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
              toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
            }else{
              toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
              toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
              toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
            }
          }
          //가장자리(아랫줄)인 경우
          else if(i==N-1){
            if(j==0){
              toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
              toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
            }else if(j==M-1){
              toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
              toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
            }else{
              toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
              toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
              toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
            }
          }
          //가장자리(왼쪽줄)인 경우
          else if(j==0){
            toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
            toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
            toma[i][j+1]=(toma[i][j+1]==-1)?-1:1;
          }
          //가장자리(오른쪽줄)인 경우
          else if(j==M-1){
            toma[i-1][j]=(toma[i-1][j]==-1)?-1:1;
            toma[i+1][j]=(toma[i+1][j]==-1)?-1:1;
            toma[i][j-1]=(toma[i][j-1]==-1)?-1:1;
          }
          ok++;
        }
      }
    }
    day++;
  }

   //입력확인
  for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout << toma[i][j];
    }
    cout << "\n";
  }

  cout << day <<endl;


}

int main() {
  nojam7576();
}