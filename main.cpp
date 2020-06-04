#include <iostream>
using namespace std;
void nojam14681(){
  int X,Y;
  cin >> X >> Y ;
  if(X>0){
    if(Y>0){
      cout << "1";
    }else{
      cout << "4";
    }
  }else{
    if(Y>0){
      cout << "2";
    }else{
      cout << "3";
    }
  }
}

int main(){
  nojam14681();
}