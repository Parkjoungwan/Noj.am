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
	long long n;
	long long arr[1000000000001] = {0,1,0,1,1};
	long long i = 5;
	cin >> n;
	while (i <= n + 1)
	{
		if (arr[i - 1] + arr[i - 3] + arr[i - 4] < 3)
			arr[i] = 1;
		else
			arr[i] = 0;
		i++;
	}
	if (arr[n] == 1)
		cout << "SK\n";
	else
		cout << "CY\n";
	return 0;
}
