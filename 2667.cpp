#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int house[25][25];
queue <pair<int,int>> q;
int direction[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
vector <int> v;

void BFS(){
	pair <int,int> current;
	int mx, my;
	int count=0;
	int num=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(house[i][j]==1){
				q.push(make_pair(i,j));
				while(!q.empty()){
					current = q.front();
					q.pop();
					for(int k=0;k<4;k++){
						mx = current.second+direction[k][0];
						my = current.first+direction[k][1];
						if(0<=mx&&mx<N&&0<=my&&my<N&&house[my][mx]==1){
							q.push(make_pair(my,mx));
							house[my][mx]=house[current.first][current.second]+1;
							count++;
						}
					}		
				}
				v.push_back(count);
				count=0;
				num++;
			}
		}
	}
	cout<<num<<"\n";
	for(int i=0;i<v.size();i++){
		cout << v[i] << "\n";
	}
}

void nojam2667(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%1d",&house[i][j]);
		}
	}
	BFS();
}

int main(){
	nojam2667();
}
