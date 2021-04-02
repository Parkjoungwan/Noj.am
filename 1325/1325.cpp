#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int vis[10001];
vector<int> com[10001];
int Num;

void DFS(int x)
{
	int i;
	int next_x;

	vis[x] = 1;
	i = 0;
	while(i < com[x].size())
	{
		next_x = com[x][i];
		if (vis[next_x] != 1)
		{
			Num++;
			DFS(next_x);
		}
		i++;
	}
}

int main()
{
	int N;
	int M;
	int i;
	int a;
	int b;
	int tmp_ans;
	vector<int> ans;

	cin >> N;
	cin >> M;
	i = 0;
	tmp_ans = -1;
	while (i < M)
	{
		cin >> a;
		cin >> b;
		com[b].push_back(a);
		i++;
	}
	i = 1;
	while (i <= N)
	{
		memset(vis, false, sizeof(vis));
		Num = 0;
		DFS(i);

		if (tmp_ans == Num)
			ans.push_back(i);
		else if (tmp_ans < Num)
		{
			tmp_ans = Num;
			ans.clear();
			ans.push_back(i);
		}
		i++;
	}
	sort(ans.begin(), ans.end());
	i = 0;
	while (i < ans.size())
	{
		cout << ans[i] << " ";
		i++;
	}
}
