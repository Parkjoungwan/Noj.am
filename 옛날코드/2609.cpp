#include <iostream>
using namespace std;

int N,M;

void gcd(){
	if(N<M){
		int swap;
		swap=N;
		N=M;
		M=swap;
	}
	int one=N;
	int two=M;
	while(1){
		if(one%two==0)break;
		int temp=two;
		two=one%two;
		one=temp;
	}
	cout<< two << "\n";
	cout<< N*M/two<<"\n";
}

void nojam2609(){
	cin >> N >> M;
	gcd();
}

void testFun(){
	cout << "test"<<endl;
}

int main(){<F8>:"
	nojam2609();
}
