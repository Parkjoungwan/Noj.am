#include <iostream>
#include <cmath>
using namespace std;
int x,y,w,h;
void nojam1085(){
	cin>> x >> y >> w >> h;
	int mx, my;
	double rp, lp;
	if(x>(w/2)){
		mx=w-x;
	}else{
		mx=x;
	}
	if(y>(h/2)){
		my=h-y;
	}else{
		my=y;
	}
	rp=(w-x)*(w-x)+(h-y)*(h-y);
	lp=x*x+y*y;
	rp=sqrt(rp);
	lp=sqrt(lp);
	int sot1, sot2; 
	sot1=(mx>my)?my:mx;
	sot2=(rp<lp)?rp:lp;
	int result;
	result=(sot1<sot2)?sot1:sot2;
	cout << result <<"\n";
}

int main(){
	nojam1085();
}
