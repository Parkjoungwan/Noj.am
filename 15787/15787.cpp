#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
int train[100001];
int tn;
int sn;
int on;
int result;

void trainset()
{
	int i;
	i = 0;

	while(i < N)
	{
		train[i] = 0;
		i++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	trainset();
	while (M--)
	{
		cin >> on >> tn;
		if (on == 1)
		{
			cin >> sn;
			train[tn] = train[tn] | (1 << sn);
		}
		if (on == 2)
		{
			cin >> sn;
			train[tn] = train[tn] & ~(1 << sn);
		}
		if (on == 3)
		{
			train[tn] = train[tn] & ~(1048576);
			train[tn] = train[tn] << 1;
		}
		if (on == 4)
		{
			train[tn] = train[tn] & ~(2);
			train[tn] = train[tn] >> 1;
		}
	}
	result = 0;
	for (int i = 1; i <= N; i++)
	{
		result++;
		for (int j = i - 1; j > 0; j--)
		{
			if (train[i] == train[j])
			{
				result--;
				break;
			}
		}
	}
	cout << result;
}
