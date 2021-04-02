#include <iostream>

using namespace std;


int main() {
	int N;
	int i;
	int result;
	int dp[100001];

	cin >> N;
	i = 1;
	result = -1001;
	dp[0] = 0;
	while (i <= N)
		cin >> dp[i++]; 
	i = 1;
	while (i <= N)
	{
		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0)
			dp[i] += dp[i - 1];
		if (result < dp[i])
			result = dp[i];
		i++;
	}
	cout << result;
	return 0;
}
