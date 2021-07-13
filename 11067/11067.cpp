#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct cf
{
	int x;
	int y;
};

bool operator < (const cf &a, const cf &b)
{
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int N;
	int x, y;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<cf> cafes(N+1);
		for (int j = 1; j <= N; j++)
		{
			cin >> x >> y;
			cafes[j].x = x;
			cafes[j].y = y;
		}
		cafes[0].x = -1;
		cafes[0].y = 0;
		sort(cafes.begin(), cafes.end());
		for (int k = 1; k <= N;)
		{
			if (cafes[k].x == cafes[k - 1].x)
				k++;
			else if (cafes[k].y == cafes[k - 1].y)
				k++;
			else {
				auto spoint = cafes.begin() + k;
				int t = cafes[k].x;
				while (++k <= N && t == cafes[k].x);
				auto epoint = cafes.begin() + k;
				reverse (spoint, epoint);
			}
		}
		int M;
		cin >> M;
		for (int l = 0; l < M; l++)
		{
			int target;
			cin >> target;
			cout << cafes[target].x << ' ' << cafes[target].y << "\n";
		}
	}
}
