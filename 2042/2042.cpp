#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
vector<long long> arr;

ft_init(long long &arr, long long &tree, int node, int start, int end)
{
	if (start == end)
		return (tree[node] = arr[start]);
	int mid = (start + end) / 2;

	return tree[node] = ft_init(arr, tree, node * 2, start, mid) +
		ft_init(arr, tree, node * 2 + 1, mid + 1, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int M;
	int K;
	int tree_size;

	cin >> N >> M >> K;
	tree_size = 1 << ((int)ceil(log2(n)) + 1);
	new long long arr [N];
	new long long tree [tree_size];
	
	for (int i = 0; i< N; i++)
	{
		cin >> arr[i];
	}
	ft_init(arr, tree, 1, 0, N);
	while (tree_size)
	{
		cout << tree[tree_size - 1] << " ";
	}
	/*while (M + K)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
		}
		else
		{
		}
	}*/
}
