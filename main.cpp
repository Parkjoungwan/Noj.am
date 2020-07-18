#include <iostream>
#include <vector>
using namespace std;

int n,k;
int dp[12];

vector <int> ans;

void dpset(int N){
	for(int i=4;i<=N;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
}

void findans(int N, int begin, int end){
	if(N==0) return ;
	int one = dp[N-1];
	int two = dp[N-2]+dp[N-1];
	int three = dp[N];
	if(N>=1&& (begin<k&&k<=begin+one)){
		ans.push_back(1);
		findans(N-1,begin, begin+one);
	}else if(N>=2&&(begin+one<k&&k<=begin+two)){
		ans.push_back(2);
		findans(N-2,begin+one,begin+two);
	}else if(N>=3&&(begin+two<k&&k<=begin+three)){
		ans.push_back(3);
		findans(N-3,begin+two,begin+three);
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
	if (dp[n]<k) {
		cout << "-1";
		return;
	}
	int end = dp[n];
	findans(n,0,end);
	show(ans);
}

int main() {
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	nojam12101();
	return 0;
}
