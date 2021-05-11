#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long ft_init(vector<long long> &arr, vector<long long> &tree,
		int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[node] = min(ft_init(arr, tree, node * 2, start, mid),
			ft_init(arr, tree, node * 2 + 1, mid + 1, end)); 
}

long long query(vector<long long> &tree, int node, int start, int end,
		int left, int right)
{
	if (left > end || right < start)
		return 10000000010;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(query(tree, node * 2, start, mid, left, right), 
			query(tree, node * 2 + 1, mid + 1, end, left, right));

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	
	cin >> n >> m;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h+1));
	
	vector <long long> arr(n);
	vector <long long> tree(tree_size);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ft_init(arr, tree, 1, 0, n - 1);

	while (m--)
	{
		int b, c;
		cin >> b >> c;
		cout << query(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}


