#include <iostream>
using namespace std;

int N,M;

void nojam2609(){
	cin >> N >> M;
	int max=1;
	for (int i=2;i<10000;i++){
		if(N%i==0&&M%i==0){
			N=N/i;
			M=M/i;
			max*=i;
		}
	}
	int min=max*M*N;
	cout << max <<"\n"<< min<<"\n";
}

int main(){
	nojam2609();
}
