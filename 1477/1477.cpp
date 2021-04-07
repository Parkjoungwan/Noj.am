#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	int n, m, l;
	int pos;
	int i;
	int start, end, mid;

	cin >> n >> m >> l;
	vector<int>store;
	store.push_back(0);
	i = 0;
	while (i < n)
	{
		cin >> pos;
		store.push_back(pos);
		i++;
	}
	store.push_back(l);
	sort(store.begin(), store.end());
	start = 1;
	end = l - 1;
	mid = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int new_store = 0;
		i = 1;
		while (i < store.size())
		{
			int dist = store[i] - store[i - 1];
			new_store += (dist / mid);
			if (dist % mid == 0)
				new_store--;
			i++;
		}
		if (new_store > m)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << start;
	return 0;
}

