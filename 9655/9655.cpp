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
	int N;
	int howin;
	cin >> N;
	howin = N % 4;
	if (howin % 2 == 0)
	{
		cout << "CY\n";
	}
	if (howin % 2 == 1)
	{
		cout << "SK\n";
	}
}
