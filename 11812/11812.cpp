#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int n;
long long int x, y;
long long int cnt;
int k, q;
int i;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k >> q;
	i = 0;
	while (i < q)
	{
		cin >> y >> x;
		cnt = 0;
		if (k == 1)
			cnt = abs(y - x);
		else 
		{
			while (y != x)
			{
				if (y > x)
					y = (y - 2) / k + 1;
				else
					x = (x - 2) / k + 1;
				++cnt;
			}
		}
		cout << cnt << '\n';
		i++;
	}
	return 0;
}
