#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long ft_init(vector<long long> &arr, vector<long long> &tree,
		int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return (tree[node] = ft_init(arr, tree, node * 2, start, mid) +
			ft_init(arr, tree, node * 2 + 1, mid + 1, end)); 
}

void ft_update(vector<long long> &tree, int node, int start,
		int end, int index, long long diff)
{
	if (!(start <= index && index <= end))
		return ;
	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		ft_update(tree, node * 2, start, mid, index, diff);
		ft_update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long sum(vector<long long> &tree, int node, int start,
		int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) +
		sum(tree, node * 2 + 1, mid + 1, end, left, right);
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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			ft_update(tree, 1, 0, n - 1, b - 1, diff);
			m--;
		}
		else
		{
			cout << sum(tree, 1, 0, n - 1, b - 1, c - 1);
			k--;
		}
	}
}
