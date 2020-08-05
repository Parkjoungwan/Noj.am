#include <iostream>
using namespace std;

int a,b,c,d,e,f;
int x,y;	

void nojam19532(){
	cin >> a >> b >> c >> d  >> e >> f ;
	int up = (a*f) - (d*c);
	int down = (a*e) - (b*d);
	y=up/down;
	x=(c-(b*y))/a;
	cout << x <<" "<< y << "\n";
}

int main(){
	nojam19532();
}
