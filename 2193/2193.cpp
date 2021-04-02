#include <iostream>

using namespace std;

int main()
{
	int N;
	int i;
	long long dpzero[91];
	long long dpone[91];

	cin >> N;
	dpzero[0] = 0;
	dpone[0] = 0;
	dpzero[1] = 0;
	dpone[1] = 1;
	i = 2;
	while (i <= N)
	{
		dpzero[i] = dpzero[i - 1] + dpone[i - 1];
		dpone[i] = dpzero[i - 1];
		i++;
	}
	cout << dpzero[N] + dpone[N];
	return 0;
}
