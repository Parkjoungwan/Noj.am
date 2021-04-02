#include <iostream>
#include <algorithm>
using namespace std;
int N;

void Show(int Num[]){
	for(int i=0;i<N;i++){
		cout<< Num[i]<<"\n";
	}
}

void nojam2751(){
	cin>>N;
	int Num[N];
	for(int i=0;i<N;i++){
		cin>>Num[i];
	}
	sort(Num,Num+N);
	Show(Num);
}

int main(){
	nojam2751();
}
