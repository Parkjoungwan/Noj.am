#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int x, y, d, g;
	int map[101][101];
	int result;
	vector<int> direction;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> y >> x >> d >> g;
		direction.clear();
		map[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		map[x][y] = 1;
		direction.push_back(d);
		for (int j = 0; j < g; j++)
		{
			int s = direction.size();
			for (int k = s - 1; k >= 0; k--)
			{
				int next = (direction[k] + 1) % 4;
				x = x + dx[next];
				y = y + dy[next];
				map[x][y] = 1;
				direction.push_back(next);
			}
		}
	}
	result = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 &&
					map[i][j + 1] && map[i + 1][j + 1] == 1)
				result++;
		}
	}
	cout << result << "\n";
}
