#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
<<<<<<< HEAD
  int N;
  cin >> N;
  int *maze=new int[N];
  for (int i=0;i<N;i++){
    cin>>maze[i];
  }
  int count=0;
  int M = N-1;
  for(;M!=0;){
    int check = 1;
    int check2 =0;
    for(int j=M-1;j>=0;j--){
      if(maze[j]>=check){
        M=j;
        check2= 1;
      }
      check++;
    }
    if(check2==0){
        cout << "-1"<<endl;
        return 0;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
=======
 std::cout<<"helloworld! you finally did it!"<<endl;
}

>>>>>>> origin/master
