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
	long long howin;
	cin >> N;
	howin = N % 4;
	if (howin % 2 == 0)
		cout << "CY\n";
	else	
		cout << "SK\n";
}
