#include<iostream>
using namespace std;

int N;

void nojam9655(){
	cin >> N;
	int check = N%4;
	if(check%2==0){
		cout << "CY\n";
	}
	if(check%2==1){
		cout << "SK\n";
	}
}

int main(){
	nojam9655();
}
