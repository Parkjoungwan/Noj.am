#include <iostream>
#include <string>

void B5337 (){
  std::cout << ".  .   .\n";
  std::cout << "|  | _ | _. _ ._ _  _\n";
  std::cout << "|/\\|(/.|(_.(_)[ | )(/.\n";
}

void B10926 (){
  std::string a;
  std::cin >> a;
  std::cout << a;
  std::cout << "??!";
}

void B16561(){
  int a;
  std::cin >> a;
  int b;
  int d=1;
  b=(a-6)/3;
  for(int c=2;c<=b;c++){
    if(a==9) d=1;
    else d=d+c;
  }
  std::cout<<d;
}
void B15680(){
  int n;
  std::cin >> n;
  if(n==0)
  {
    std::cout << "YONSEI";
  }
  else std:: cout << "Leading the Way to the Future";
}

void B16394(){
  int a;
  std::cin >> a;
  std:: cout << a-1946;
  
}

int main() {
  //2020년 3월 17일
  //B5337();
  //B10926();
  //B16561();
  //B15680();
  B16394();
}