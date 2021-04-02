#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int *fd_check(int *sang, int *nosang, int N, int M)
{
	int mid, start, end, target;
	int head, tail;
	int i;
	int *count;
	
	count = new int[M];
	i = 0;
	while (i < M)
	{
		start = 0;
		end = N - 1;
		while (end > start)
		{
			mid = (start + end) / 2;
			target = nosang[i];
			if (sang[mid] >= target)
				end = mid;
			else
				start = mid + 1;
		}
		head = end;
		start = 0;
		end = N - 1;
		while (end > start)
		{
			mid = (start + end) / 2;
			target = nosang[i];
			if (sang[mid] > target)
				end = mid;
			else
				start = mid + 1;
		}
		tail = end;
		if (tail == N - 1 && sang[N - 1] == nosang[i])
			tail++;
		count[i] = tail - head;
		i++;
	}
	return (count);
}

int	main()
{
	int N;
	int M;
	int i;
	int *sang;
	int *nosang;
	int *count;

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
	count = fd_check (sang, nosang, N, M);
	i = 0;
	while (i < M)
	{
		cout << count[i] << " ";
		i++;
	}
	free(sang);
	free(nosang);
	free(count);
}
