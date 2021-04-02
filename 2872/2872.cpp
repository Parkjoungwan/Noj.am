#include <iostream>
using namespace std;
int stack[300001];

int main()
{
	int N;
	int i;
	int j;
	int count;
	int last;

	cin >> N;
	i = 0;
	j = N - 1;
	last = N;
	count = 0;
	while (i < N)
		cin >> stack[i++];
	while (j >= 0)
	{
		if (stack[j] == last)
		{
			count++;
			last--;
		}
		j--;
	}
	cout << N - count;
}
