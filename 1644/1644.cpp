#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int check;
	int num;
	int front, rear;
	int sum, result;
	int dp[2000000] = {0,};
	cin >> n;
	num = 0;
	sum = front = rear = result = 0;
	for (int j = 2; j <= n; j++)
	{
		check = 0;
		for (int i = 2; i*i <= j; i++)
		{
				if (j % i == 0)
				{
					check = 1;
					break;
				}
		}
		if (!check)
			dp[num++] = j;  
	}
	/*
	int i = 0;
	while (dp[i])
	{
		cout << dp[i++] << " ";
	}
	*/
	while (1)
	{
		if (n <= sum)
			sum -= dp[front++];
		else if (rear == num)
			break;
		else
			sum += dp[rear++];
		if (sum == n)
			result++;
	}
	cout << result << "\n";
}
