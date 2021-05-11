#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int ft_min(int x, int y, int z)
{
	if (x > y)
		x = y;
	if (x > z)
		x = z;
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int arr[1001] = {0,0,1,0,1};
	int i = 5;
	while (i < 1001)
	{
		if (ft_min(arr[i - 1],arr[i - 3], arr[i - 4]) == 1)
			arr[i] = 0;
		else
			arr[i] = 1;
		i++;
	}
	while(1)
	{
		cin >> n;
		if (arr[n] == 1)
			cout << "SK\n";
		else
			cout << "CY\n";
	}
	return 0;
}
