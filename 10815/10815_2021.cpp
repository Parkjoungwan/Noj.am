#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fd_check(int *sang, int *nosang, int N, int M)
{
	int i;
	int check;
	int end;
	int start;
	int mid;
	int target;

	i = 0;
	while (i < M)
	{
		target = nosang[i];
		check = 0;
		end = N - 1;
		start = 0;
		mid = (end - start) / 2;
		while (end - start >= 0)
		{
			if (sang[mid] == target)
			{
				nosang[i] = 1;
				check = 1;
				break;
			}
			else if (sang[mid] <= target)
			{
				start = mid + 1;
			}
			else
				end = mid - 1;
			mid = (end + start) / 2;
		}
		if (check != 1)
		{
			nosang[i] = 0;
		}
		i++;
	}
}

int	main()
{
	int N;
	int M;
	int i;
	int *sang;
	int *nosang;

	cin >> N;
	i = 0;
	sang = new int[N];
	while (i < N)
	{
		cin >> sang[i];
		i++;
	}
	sort(sang, sang + N);
	i = 0;
	cin >> M;
	nosang = new int[M];
	while (i < M)
	{
		cin >> nosang[i];
		i++;
	}
	fd_check (sang, nosang, N, M);
	i = 0;
	while (i < M)
	{
		cout << nosang[i] << " ";
		i++;
	}
}
