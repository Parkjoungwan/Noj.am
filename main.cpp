#include <iostream>
#include <vector>
using namespace std;

void bake11021(){
  int t;
  cin >> t;
  for (int i=0;i<t;i++){
    int a,b;
    cin >>a>>b;
    cout << "Case #";
    cout << i+1;
    cout << ": ";
    cout << a+b<<endl;
  }
}

int main() {
  bake11021();
}