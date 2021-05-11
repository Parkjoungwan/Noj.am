#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N;
	cin >> N;
	int arr[8] = {0, 1, 0, 1, 1, 1, 1, 0};
	N %= 7;
	if (arr[N])
		cout << "SK\n";
	else
		cout << "CY\n";
}
