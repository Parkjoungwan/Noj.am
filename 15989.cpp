#include <iostream>

using namespace std;

int N;
long long dp[10000];

void dpset(){

	for(int i=6;i<=N;i++){
		if(dp[i]==0){ 
		dp[i]=dp[i-1]+(dp[i-2]-dp[i-3])+(dp[i-3]-dp[i-4]-dp[i-5]+dp[i-6]);
		}
	}
}

void nojam15989(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
 		cin >> N;
		if(N>6){
			dpset();
		}
		cout<< dp[N]<<"\n";
	}
}


int main(){
	dp[0]=1;
	for(long long i=1;i<6;i++){
		dp[i]=i;
	}
	nojam15989();
}
