#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

int N, r, c;
int result = 0;
int bear[2][2] = {{0, 1}, {2, 3}};

void	fd_check()
{
	int num = pow(2, N);
	int beary = (num / 2) - 1 < r ? 1 : 0;
	int bearx = (num / 2) - 1 < c ? 1 : 0;
	N--;
	result += bear[beary][bearx] * pow(2, N) * pow(2, N);
	if (beary)
		r -= pow(2, N);
	if (bearx)
		c -= pow(2, N);
	if (N == 0)
		return;
	fd_check();
}

int		main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> r >> c;
	fd_check();
	cout << result;
	return 0;
}
