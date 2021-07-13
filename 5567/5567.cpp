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
	int N;
	int M;
	int rel[501][501];
	int result;
	bool sang[501];
	bool invite[501];
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		rel[x][y] = 1;
		rel[y][x] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		if (rel[1][i] == 1)
		{
			invite[i] = true;
			sang[i] = true;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (sang[i])
		{
			for (int j = 1; j <= N; j++)
			{
				if (rel[i][j])
					invite[j] = true;
			}
		}
	}
	result = 0;
	for (int i = 2; i <= N; i++)
		if(invite[i])
			result++;
	cout << result << "\n";
}
