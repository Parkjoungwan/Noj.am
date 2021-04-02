#include <iostream>
#include <cstring>
#define DIST(a, b, c, d) ((a - c) * (a - c) + (b - d) * (b - d))
using namespace std;

int a[1001][2] = {{0, 0}};
int visit[1001];
int n, k, limit;

bool fd_possible(int i, int count)
{
	int j;

	if (count < 1)
		return false;
	visit[i] = 1;
	j = 1;
	while (j < n)
	{
		if ((!visit[j] && DIST(a[i][0], a[i][1], a[j][0], a[j][1]) <= limit) &&
				(DIST(a[j][0], a[j][1], 10000, 10000) <= limit || fd_possible(j, count - 1)))
			return true;
		j++;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	int start, end;

	cin >> n;
	cin >> k;
	i = 1;
	while (i < n)
	{
		cin >> a[i][0];
		cin >> a[i][1];
		i++;
	}
	start = 1;
	end = 15000;
	while (start <= end)
	{
		memset(visit, 0, sizeof(visit));
		int mid = (start + end) / 2;
		limit = mid * mid * 100;
		if (fd_possible(0, k))
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << start;
}
