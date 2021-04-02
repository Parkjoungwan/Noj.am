#include <iostream>
using namespace std;

int main()
{
	int N;
	int C;
	int i;
	int *arr;

	cin >> N;
	cin >> C;
	arr = new int[N];
	i = 0;
	while (i < N)
	{
		cin >> arr[i];
		i++;
	}
	sort(arr, arr + N);

	int start, end, mid;
	int d;
	int ans, count, target;

	start = 1;
	end = arr[N - 1] - arr[0];
	d = 0;
	count = 1;
	while (start <= end)
	{
		i = 1;
		mid = (start + end) / 2;
		count = 1;
		target = arr[0];
		while (i < N)
		{
			d = arr[i] - target;
			if (mid <= d)
			{
				count++;
				target = arr[i];
			}
			i++;
		}
		if (count >= C)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << ans;
}
