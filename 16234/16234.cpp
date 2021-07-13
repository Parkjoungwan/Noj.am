#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int L;
int R;
int map[51][51];
bool visit[51][51];

bool combin_check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			if (L <= abs(map[x][y] - map[nx][ny]) &&
					R >= abs(map[x][y] - map[nx][ny]))
				return true;
	}
	return false;
}

bool combin_check2(int x, int y, int nx, int ny)
{
	if (L <= abs(map[x][y] - map[nx][ny]) &&
			R >= abs(map[x][y] - map[nx][ny]))
		return true;
	return false;
}

void BFS(int a, int b)
{
	int sum;
	int count;
	int value;

	sum = 0;
	count = 0;
	queue<pair<int, int> > q;
	queue<pair<int, int> > nq;
	q.push(make_pair(a, b));
	nq.push(make_pair(a, b));
	visit[a][b] = true;
	while (q.empty() == 0)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		sum +=  map[x][y];
		count++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visit[nx][ny] != 0)
				continue;
			if (combin_check2(x, y, nx, ny))
			{
				visit[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				nq.push(make_pair(nx, ny));
			}
		}
	}
	value = sum / count;
	while (nq.empty() == 0)
	{
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();
		map[x][y] = value;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int day;
	bool check;
	
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	day = 0;
	check = true;
	while (check)
	{
		check = false;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == false && combin_check(i, j))
				{
					BFS(i, j);
					check = true;
				}
			}
		if (check)
			day++;
		memset(visit, false, sizeof(visit));
	}
	cout << day << "\n";
}
