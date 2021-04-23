#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int width[16][16];
int min(int a, int b){ return a < b ? a : b;}

int ft_dfs(int visit, int )
{
	int ret;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> width[i][j];
		}
	}
	cout << ft_dfs(0);

}
