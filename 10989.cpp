#include <iostream>
using namespace std;

int N;
int Num[10001]={0,};
void Show(){
	for(int i=0;i<10000;i++){
		for(int j=0;j<Num[i];j++){
			cout << i<<"\n";
		}
	}
}

void nojam10989(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++){
		int num;
		cin >>num;
		Num[num]++;
	}
	Show();
}

int main(){
	nojam10989();
}
