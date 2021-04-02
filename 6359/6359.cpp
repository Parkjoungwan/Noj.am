#include <iostream>

using namespace std;

int main()
{
	int T;
	int N;
	int i;
	int j;
	int result;

	cin >> T;
	i = 1;
	while (i <= T)
	{
		cin >> N;
		j = 1;
		while (j <= N)
		{
			if (j * j <= N)
				result++;
			j++;
		}
		j = 0;
		cout << result << '\n';
		result = 0;
		i++;
	}
	return 0;
}
