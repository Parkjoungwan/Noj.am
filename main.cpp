#include <iostream>
#include <string>
void B10996(){
  int N;
  std::cin >> N;
  if(N==1) std::cout << "*";
  else{
    for(int i=0;i<2*N;i++)
    {
      if(i%2==1){
        std::cout << " ";
        for(int k=0;k<N/2;k++)
        {
          std::cout << "*";
          std::cout << " ";
        }
      }
      else{
        if(N%2==0){
          for(int j=0;j<N/2;j++)
          {
            std::cout << "*";
            std::cout << " ";
          }
        }
        else{
          for(int j=0;j<N/2+1;j++)
          {
            std::cout << "*";
            std::cout << " ";
          }
        }
      }
      std::cout << "\n";
    }
  }
}
int main() {
 B10996(); 
}

