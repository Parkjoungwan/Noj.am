#include <iostream>
#include <cmath>
using namespace std;

int T;
int a, b;
void nojam1009(){
	cin >> T;	
	for(int i=0;i<T;i++){
		cin >> a >> b;
		a%=10;
		b%=4;
		if(b==0)b=4;
		int ans = (int)pow(a,b)%10;
		if(ans==0)ans=10;
		cout << ans << "\n";
	}
}

int main(){
	nojam1009();
}
