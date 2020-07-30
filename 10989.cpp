#include <iostream>
using namespace std;

long long N;
long long  Num[10001]={0,};
void Show(){
	for(int i=0;i<10001;i++){
		for(long long j=0;j<Num[i];j++){
			cout << i<<"\n";
		}
	}
}

void nojam10989(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(long long i=0;i<N;i++){
		long long num;
		cin >>num;
		Num[num]++;
	}
	Show();
}

int main(){
	nojam10989();
}
