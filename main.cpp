#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Things{
	int W;
	int V;
};

void nojam12865(){
	int N,K;
	cin >> N;
	cin >> K;
	Things things[N];
	for(int i=0;i<N;i++){
		cin>>things[i].W;
		cin>>things[i].V;
	}	
	for(int i=0;i<N;i++){
		cout<<things[i].W;
		cout<<things[i].V;
	}
}

int main() {
  nojam12865();
}
