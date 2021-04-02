#include <iostream>
#include <algorithm>

using namespace std;

int	main(){
	int N;
	int i;
	int dp[10001];
	int arr[10001];

	cin >> N;
	i = 1;
	dp[0] = 0;
	arr[0] = 0;
	while (i <= N){
		cin >> arr[i];
		dp [i] = 0;
		i++;
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	i = 3;
	while (i <= N){
		dp[i] = max(dp[i - 3] + arr[i] + arr[i - 1], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
		i++;
	}
	cout << dp[N];
}
