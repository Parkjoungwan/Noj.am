#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
const int low = -1000000001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int x, y;
	int result;
	int front, rear;

	cin >> N;
	pi line[1000000];
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		line[i] = pi(x, y);
	}
	sort(line, line + N);
	result = 0;
	front = low;
	rear = low;
	for (int i = 0; i < N; i++)
	{
		if (rear < line[i].first)
		{
			result += rear - front;
			front = line[i].first;
			rear = line[i].second;
		}
		else
			rear = max(rear, line[i].second);
	}
	result += rear - front;
	cout << result;
}
