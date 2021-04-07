#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double x, y, c;

double fd_width(double mid)
{
	double h1 = sqrt(x * x - mid * mid);
	double h2 = sqrt(y * y - mid * mid);
	return (h1 * h2)/(h1 + h2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> x >> y >> c;
	double start, end, mid;
	double result;

	start = 0;
	end = min(x, y);
	
	while (end - start > 0.000001 )
	{
		mid = (start + end) / 2.0;
		if (fd_width(mid) >= c)
		{
			result = mid;
			start = mid;
		}
		else
			end = mid;
	}
	printf("%.3lf\n", result);
	return 0;
}
