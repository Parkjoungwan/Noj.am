#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Line
{
	int left;
	int right;
};

bool compare (const Line a, const Line b)
{
	return a.right < b.right;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x;
	int y;
	int d;
	int result;
	int N;

	result = -1;
	cin >> N;
	Line line[100001];
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		line[i].left = x < y ? x : y;
		line[i].right = x > y ? x : y;
	}
	cin >> d;
	sort (line, line + N, compare);
	priority_queue<int> pq;
	for (int i = 0; i < N; i++)
	{
		pq.push(-line[i].left);
		while(!pq.empty() && -pq.top() < line[i].right - d)
			pq.pop();
		result = result > (int)pq.size() ? result : (int)pq.size();
	}
	cout << result;
}
