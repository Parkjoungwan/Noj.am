#include <iostream>
#include <vector>
using namespace std;

int n,k;
int dp[12];

vector <int> ans;

void dpset(int N){
	for(int i=3;i<N;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	//input end
	for(int i=1;i<=N;i++){
		for(int j=K; j>=1; j--){
			if(w[i] <= j){
				d[j] = max(d[j], d[j-w[i]] + v[i]);
			}
		}
=======
}

void findans(int N,int K){
	if(N<3) return;
	if(K<dp[N-1]){
		ans.push_back(1);
		findans(N-1,K);}
	if(K>dp[N-1]&&K<dp[N-1]+dp[N-2]){
		ans.push_back(2);
		findans(N-2,K-dp[N-1]);
	}
	if(K>dp[N-1]+dp[N-2]){
		ans.push_back(3);
		findans(N-3,K-dp[N-1]-dp[N-2]);
	}
}
void show(vector <int> ANS){
	for(int i=0;i<ANS.size();i++){
		cout<<ANS[i];
		if(i<ANS.size()-1) cout<<"+";
	}
}

void nojam12101(){
	cin >> n >> k;
	dpset(n);
	cout << "dp reset\n";
	findans(n,k);
	cout << "findans\n";
	show(ans);
}





int main() {
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	nojam12101();
	return 0;
}
