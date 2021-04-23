#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int learn;
int n, k;
int word[50];

int	ft_dfs(int start, int alnum)
{
	int ret;

	ret = 0;
	if (alnum == k)
	{
		for (int i = 0; i < n; i ++)
		{
			if ((word[i] & learn) == word[i])
				ret++;
		}
		return ret;
	}
	for (int i = start; i < 26; i++)
	{
		if ((learn & (1 << i)) == 0)
		{
			learn |= 1 << i;
			ret = max (ret, ft_dfs(i + 1, alnum + 1));
			learn &= ~(1 << i);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	learn |= 1 << ('a' - 'a');
	learn |= 1 << ('n' - 'a');
	learn |= 1 << ('t' - 'a');
	learn |= 1 << ('i' - 'a');
	learn |= 1 << ('c' - 'a');

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			word[i] |= 1 << (str[j] - 'a');
		}
	}
	if (k < 5 || k == 26)
	{
		cout << (k == 26 ? n : 0);
		return 0;
	}
	cout << ft_dfs(1, 5);
	return 0;
}


