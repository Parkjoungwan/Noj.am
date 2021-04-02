#include <iostream>

using namespace std;

int main()
{
	int T;
	int N;
	int i;
	int j;
	int k;
	int a[101];

	cin >> T;
	i = 1;
	while (i <= T)
	{
		cin >> N;
		j = 1;
		while (j <= N)
			cin >> a[j++];
		k = 0;
		while (k <= 100)
		{
			j = 1;
			while (j <= N)
			{
				if (a[j] == k)
				{
					cout << k << " ";
					break;
				}
				j++;
			}
			k++;
		}
		j = 1;
		while (j <= N)
		{
			k = j + 1;
			while (k <= N)
			{
				if (a[j] == a[k])
					cout << a[j] << " ";
				k++;
			}
			j++;
		}
		cout << '\n';
		i++;
	}

}
