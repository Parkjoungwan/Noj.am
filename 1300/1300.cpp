#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		main()
{
	int N;
	int k, i;
	int start, end, mid, target;
	int	result;

	cin >> N;
	cin >> k;
	result = 0;
	start = 1;
	end = k;
	while (start <= end)
	{
		mid = (start + end) / 2;
		target = 0;
		i = 1;
		while (i <= N)
		{
			target += min(mid / i, N);
			i++;
		}
		if (target < k)
			start = mid + 1;
		else
		{
			result = mid;
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}
