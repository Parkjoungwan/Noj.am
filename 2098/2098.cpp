#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 16000001

using namespace std;

int n;
int width[16][16];
int min(int a, int b){ return a < b ? a : b;}
int d[1 << 16][16] = {0, };

int ft_dfs(int visit, int now)
{
	visit |= (1 << now);
	if (visit == (1 << now) - 1)
	{
		if (width[now][0] > 0)
		{
			return width[now][0];
		}
		return MAX;
	}

	int& ret = d[visit][now];
	if (ret > 0)
		return ret;
	ret = MAX;
	for (int i = 0; i < n; i++)
	{
		if (i != now && (visit & (1 << i)) == 0 && width[now][i] > 0)
		{
			int temp = ft_dfs(visit, i) + width[now][i];
			if (ret > temp)
				ret = temp;
		}
	}
	return ret;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> width[i][j];
		}
	}
	int ans = ft_dfs(0, 0);
	if (ans == MAX) cout << "-1";
	else cout << ans;

	return 0;
}
