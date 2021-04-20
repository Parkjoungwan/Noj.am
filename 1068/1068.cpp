#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num[50];
	int n;
	int i, j;
	int k;

	i = 0;
	cin >> n;
	while (i < n)
		cin >> num[i++];
	cin >> k;
	i = 0;
	num[k] = -1;
	while (i < n)
	{
		if (num[i] == k)
			num[i] = -1;
		i++;
	}
	i = n;
	while (--i)
		num[num[i]] = -1;
	i = 0;
	while (i < n)
		cout << num[i++] << " ";
}
