#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int min(int a, int b) 
{
	return a > b ? b : a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int arr[100000];
	int front, rear;
	int sum, count, result;
	
	front = 0;
	rear = 0;
	sum = 0;
	result = 1000001;
	count = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while(1)
	{
		if (sum >= m)
		{
			sum -= arr[front++];
			result = min(count, result);
			count--;
		}
		else if(rear == n)
			break;
		else
		{
			sum += arr[rear++];
			count++;
		}
	}
	if (result == 1000001)
		result = 0;
	cout << result << "\n";
}
