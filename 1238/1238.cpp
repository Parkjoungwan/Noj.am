#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

struct edge
{
	int end;
	int weight;
	edge(int a, int b) {
		end = a;
		weight = b;
	}
	bool operator<(const edge& e)const {
		return weight > e.weight;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, x;
	int s, e, w;
	int result = 0;

	cin >> n >> m >> x;
	vector<edge> graph[1001];
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> w;
		graph[s].push_back(edge(e, w));
	}
	vector<vector<int> > dist(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; i++)
	{
		priority_queue<edge> PQ;
		PQ.push(edge(i, 0));
		dist[i][i] = 0;

		while (PQ.empty() == 0)
		{
			e = PQ.top().end;
			w = PQ.top().weight;
			PQ.pop();

			if (w > dist[i][e]) continue;
			for (auto it = graph[e].begin(); it != graph[e].end(); it++)
			{
				int a, b;
				a = (*it).end;
				b = (*it).weight;

				if (dist[i][a] > dist[i][e] + b)
				{
					dist[i][a] = dist[i][e] + b;
					PQ.push(edge(a, dist[i][a]));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dist[x][i] + dist[i][x]);
	}
	cout << result;
}
