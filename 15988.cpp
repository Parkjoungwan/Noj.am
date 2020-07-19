#include <iostream>
using namespace std;

int N;
long long dp[1000001];

void dpset(int N){
	for(int i=4;i<=N;i++){
		dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
	}
}
void nojam15988 (){
	cin >> N;
	dpset(N);
	cout << dp[N]<<"\n";
}

int main(){
	dp[0]=dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		nojam15988();
	}
}
