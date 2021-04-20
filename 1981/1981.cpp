#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
int N, Max, Min;
int arr[100][100];
bool visit[100][100];
int i, j, k, l;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool fd_bfs(int mid)
{
	queue< pair<int, int> > que;
	i = Min;
	while (i < Max)
	{
		memset(visit, true, sizeof(visit));
		j = 0;
		while (j < N)
		{
			k = 0;
			while (k < N)
			{
				if (i <= arr[j][k] && arr[j][k] <= i + mid)
					visit[j][k] = false;
				k++;
			}
			j++;
		}
		que.push(make_pair(0,0));
		while (!que.empty())
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();

			if (visit[x][y] == true)
				continue;
			visit[x][y] = true;
			if (x == N - 1 && y == N - 1)
				return true;
			l = 0;
			while (l < 4)
			{
				int nx = x + dx[l];
				int ny = y + dy[l];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N)
					que.push(make_pair(nx, ny));
				l++;
			}
		}
		i++;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int start, mid, end;

	Max = -1;
	Min = 201;
	cin >> N;
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			cin >> arr[i][j];
			if (arr[i][j] > Max)
				Max = arr[i][j];
			if (arr[i][j] < Min)
				Min = arr[i][j];
			j++;
		}
		i++;
	}
	start = 0;
	end = Max - Min;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (fd_bfs(mid))
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << end + 1;
}
