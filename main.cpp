#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void nojam10866(){
  int N;
  cin >> N;
  vector<int> deck;
  for (int i=0;i<N;i++){
    string s;
    cin >> s;
    if(s=="push_front"){
      int X;
      cin >> X;
      deck.insert(deck.begin(),X);
    }else if(s=="push_back"){
      int X;
      cin >> X;
      deck.push_back(X);
    }else if(s=="pop_front"){
      if(deck.empty()){
        cout<<"-1"<<endl;
      }else {
        cout<<deck.front()<<endl;
        deck.erase(deck.begin());
      }
    }else if(s=="pop_back"){
      if(deck.empty()){
        cout<<"-1"<<endl;
      }else {
        cout<<deck.back()<<endl;
        deck.pop_back();
      }
    }else if(s=="size"){
      cout<<deck.size()<<endl;
    }else if(s=="empty"){
      cout<<deck.empty()<<endl;
    }else if(s=="front"){
      if(deck.empty()){
        cout<<"-1"<<endl;
      }else cout<<deck.front()<<endl;
    }else{
      if(deck.empty()){
        cout<<"-1"<<endl;
      }else cout<<deck.back()<<endl;
    }
  }


}

int main() {
  nojam10866();
}


