#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int Ed_info[20001][200001];
int Ve_least[20001] = {0};
int visited[20001] = {0};

void ft_make_info(int Ve)
{
	int u, v, w;

	cin >> u >> v >> w;
	Ed_info[u][v] = w;
}

void ft_find_least(int Ve, int start)
{
	int i, j;

	i = 1;
	while(i <= Ve)
	{
		Ve_least[i] = Ed_info[start][i];
		i++;
	}
	i = 1;
	j = 1;
	while (i <= Ve)
	{
		j = 1;
		if (visited[i] == 0 && i != start)
		{
			while (j <= Ve)
			{
				Ve_least[j] < Ve_least[i] + Ed_info[i][j] ? :Ve_least[j] = Ve_least[i] + Ed_info[i][j];
				j++;
			}
			visited[i] = 1;
		}
		i++;
	}
	i = 1;
	while (i <= Ve)
	{
		if (i == start)
			cout << "0";
		else if (Ve_least[i] < 300000)
			cout << Ve_least[i];
		else
			cout << "INF";
		cout << "\n";
		i++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Ve, Ed;
	int start;

	cin >> Ve >> Ed;
	cin >> start;
	for (int i = 0;i <= Ve; i++)
		for (int j = 0; j <= Ve; j++)
		{
			Ed_info[i][j] = 300001;
		}
	while(Ed--)
	{
		ft_make_info(Ve);
	}
	ft_find_least(Ve, start);
}
