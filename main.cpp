#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
void nojam1475(){
  string num;
  cin >> num ;
  int check[10]={0,};
  for(int i=0;i<num.size();i++){
    int N=num[i]-'0';
    check[N]++;
  }
  check[6]=(check[6]+check[9]+1)/2;
  int max=0;
  int maxnum=0;
  for(int i=0;i<9;i++){
    if(max<check[i]){
      max=check[i];
    }
  }
  cout << max;
}
 
int main() {
  nojam1475();
}