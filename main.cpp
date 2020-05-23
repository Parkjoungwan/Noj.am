#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
void nojam1021(){
  //입력시작
  int M,N;
  cin >>M;
  cin >>N;
  int* arr=new int[M];
  for(int i=0;i<M;i++){
    arr[i]=i+1;
  }
  int* target=new int[N];
  for(int i=0;i<N;i++){
    cin>>target[i];
  }
  //입력끝
  //함수시작
  int sum = 0;
  for(int i=0;i<N;i++){
    int front=0;
    for(int j=0;j<M;j++){
      if(target[i]==arr[j]){
        break;
      }else{
        front++;
      }
    }
    //타겟 넘버까지의 길이 측정완료
    int middle = M/2;
    int* cpyarr = new int[M-1];
    int count = 0;
    if(front<=middle){
      //앞으로 밀어주기
      count = front;
    }else{
      //뒤로 밀어주기
      count = M-front;
    }
    //바뀐 배열 정리
    for(int k=0;k<M-front-1;k++){
        cpyarr[k]=arr[front+k+1];
    }
    int num=0;
    for(int l=M-front-1;l<M-1;l++){
      cpyarr[l]=arr[num];
      num++;
    }
    arr= cpyarr;
    sum+=count;
    M=M-1;
  }
  //함수끝
  //출력
  cout << sum << endl;
}

int main() {
  nojam1021();
}