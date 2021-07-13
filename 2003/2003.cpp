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
	int arr[10000];
	int n, m;
	int front, rear;
	int sum, result;

	sum = 0;
	front = 0;
	rear = 0;
	result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while(1)
	{
		if (m <= sum)
			sum -= arr[front++];
		else if (rear == n)
			break;
		else
			sum += arr[rear++];
		if (sum == m)
			result++;
	}
	cout << result << "\n";
}
