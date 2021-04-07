#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int map[100][100];
bool visit[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end, mid;
	int n, i, j;
	int max, min;

	cin >> n;
	i = 0;
	j = 0;
	max = -1;
	min = 201;
	while (i < n)
	{
		while (j < n)
		{
			cin >> map[i][j];
			if (map[i][j] > max)
				max = map[i][j];
			if (map[i][j] < min)
				min = map[i][j];
			j++;
		}
		i++;
	}


	start = 0;
	end = 
}
