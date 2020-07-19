#include <iostream>
using namespace std;
long long A,B,C;

long long findans(int b){
	if(b==1){
		return A;	
	}
	if(b%2==0){
		long long half=findans(b/2);
		return (half*half)%C;
	}else{
		long long half=findans(b/2);
		long long half2=findans(b/2+1);
		return (half*half2)%C;
	}
}

void nojam1629(){
	cin >> A >> B >> C;	
	cout << findans(B)<<"\n";	

}

int main(){
	nojam1629();
	
}
