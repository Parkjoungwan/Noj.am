#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> tree[51];
int visit[51];
int root, res;

void bfs(int del)
{
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	if (root == del) return;
	q.push(root);
	visit[root] = 1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < tree[x].size(); i++)
		{
			int nx = tree[x][i];
			if (nx == del || visit[nx] != 0)continue;
			q.push(nx);
			visit[x]++;
			visit[nx] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == -1) root = i;
		else tree[tmp].push_back(i);
	}

	int del;
	cin >> del;
	bfs(del);

	res = 0;
	for (int i = 0; i < n; i++)
		if (visit[i] == 1)
			res++;
	cout << res;
}
