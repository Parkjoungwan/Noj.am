#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define DI 10000000007

using namespace std;



long long ft_init(vector<long long> &arr, vector<long long> &tree,
		int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[node] = ((ft_init(arr, tree, node * 2, start, mid) % DI) *
			(ft_init(arr, tree, node * 2 + 1, mid + 1, end)) % DI) % DI; 
}

long long ft_update(vector<long long> &tree, int node, int start,
		int end, int index, long long c)
{
	if (!(start <= index && index <= end))
		return tree[node];

	if (start == end)
		return tree[node] = c;
	int mid = (start + end) / 2;
	return tree[node] = ft_update(tree, node * 2, start, mid, index, c) * 
		ft_update(tree, node * 2 + 1, mid + 1, end, index, c) % DI;
}

long long mul(vector<long long> &tree, int node, int start,
		int end, int left, int right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return (mul(tree, node * 2, start, mid, left, right) *
		mul(tree, node * 2 + 1, mid + 1, end, left, right)) % DI;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	int tree_size;
	
	cin >> n >> m >> k;
	tree_size = 1 << ((int)ceil(log2(n)) + 1);
	
	vector <long long> arr(n);
	vector <long long> tree(tree_size);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ft_init(arr, tree, 1, 0, n - 1);
	
	while (m + k)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b;
			long long c;
			cin >> b >> c;
			ft_update(tree, 1, 0, n - 1, b - 1, c);
			m--;
		}
		else
		{
			int b, c;
			cin >> b >> c;
			cout << mul(tree, 1, 0, n - 1, b - 1, c - 1 ) % DI << "\n";
			k--;
		}
	}
	return 0;
}
