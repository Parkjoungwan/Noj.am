#include <iostream>
#include <string>
void B14624(){
  int a;
  std::cin >> a;
  if(a%2==0)
  {
    std::cout << "I LOVE CBNU";
  }
  else 
  {
    for(int i=0;i<a;i++)
    std::cout<<"*";
    std::cout<<"\n";
    int m=-1;
    for(int k=0;k<a/2+1;k++)
    {
      for(int j=a/2;j>k;j--)
      {
        std::cout<<" ";
      }
      std::cout <<"*";
      for(int l=0;l<m;l++)
      {
        std::cout<<" ";
      }
      if(k!=0)std::cout<<"*";
      std::cout<<"\n";
        m+=2;
    }
  }
}
int main() {
  B14624();  
}