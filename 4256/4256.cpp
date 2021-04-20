#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int T;
int N;
int a[1001];
int b[1001];

void sol(int i, int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		cout << a[i] << ' ';
		return;
	}
	int tmp = b[a[i]];
	sol(i + 1, l, tmp - 1);
	sol(i + tmp - l + 1, tmp + 1, r);
	cout << a[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> a[i];
		for (int i = 1; i <= N; ++i)
		{
			int tmp;
			cin >> tmp;
			b[tmp] = i;
		}

		sol(1, 1, N);
		cout << '\n';
	}
	return 0;
}
