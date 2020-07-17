#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void nojam12865(){
	int N,K;
	int d[100001];
	int w[101];
	int v[101];

	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> w[i] >> v[i];
	}
	//input end
	for(int i=1;i<=N;i++){
		for(int j=K; j>=1; j--){
			if(w[i] <= j){
				d[j] = max(d[j], d[j-w[i]] + v[i]);
			}
		}
	}
	//knapsack algorithm
	cout << d[K] << "\n";

}

int main() {
  nojam12865();
  return 0;
}
