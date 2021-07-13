#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"

using namespace std;

int v, e, start;
int dist[20001];
vector<pair<int, int> > vertex[20001];

void ft_find_least()
{
	priority_queue<pair<int, int> > PQ;
	PQ.push(make_pair(0, start));
	dist[start] = 0;
	while (PQ.empty() == 0)
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < vertex[cur].size(); i++)
		{
			int next = vertex[cur][i].first;
			int ncost = vertex[cur][i].second;
			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == 300001)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= v; i++)
		dist[i] = 300001;
	ft_find_least();
}
