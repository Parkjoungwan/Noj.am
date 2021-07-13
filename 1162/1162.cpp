#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>
typedef long long ll;

using namespace std;

int N, M, K;
vector<pair<ll, ll> > adj[10001];

vector<vector<ll> > dijkstra(int src)
{
	priority_queue<pair<ll, pair<ll, ll> > > PQ;
	vector<vector<ll> > dist(10001, vector<ll>(21, 987654321));

	dist[src][K] = 0;
	PQ.push(make_pair(0, make_pair(src, K)));
	while(PQ.empty() == 0)
	{
		ll cost = -PQ.top().first;
		ll here = PQ.top().second.first;
		ll k = PQ.top().second.second;
		PQ.pop();
		if (dist[here][k] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			ll there = adj[here][i].first;
			ll nextDist = cost + adj[here][i].second;

			if (dist[there][k] > nextDist)
			{
				dist[there][k] = nextDist;
				PQ.push(make_pair(-nextDist, make_pair(there, k)));
			}

			if (k > 0 && (dist[there][k - 1] > cost))
			{
				dist[there][k - 1] = cost;
				PQ.push(make_pair(-cost, make_pair(there, k - 1)));
			}
		}
	}
	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	ll a, b, val;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b >> val;
		adj[a].push_back(make_pair(b, val));
		adj[b].push_back(make_pair(a, val));
	}

	vector<vector<ll> > dist = dijkstra(1);

	ll min_time = 987654321;
	for (int i = 0; i < K; i++)
	{
		min_time = min(min_time, dist[N][i]);
	}
	cout << min_time << '\n';
}
