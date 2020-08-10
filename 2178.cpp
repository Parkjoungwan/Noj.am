#include <iostream>
#include <queue>
using namespace std;

int N, M;
//queue for x,y
queue <pair<int,int>> q;
//direcction for move
int direction[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int maze[101][101];


void BFS(){
	//start is 0,0
	q.push(make_pair(0,0));
	//curreent for queue pop 
	pair <int,int> current;
	int mx, my;
	while(!q.empty()){
		current = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			//move follow direction
			mx = current.second+direction[i][0];
			my = current.first+direction[i][1];
			//if mx, my is not over N,M and maze[N][M] is open door
			if(0<=mx&&mx<M&&0<=my&&my<N&&maze[my][mx]==1){
				q.push(make_pair(my,mx));
				//change maze 1 to moving count
				maze[my][mx]=maze[current.first][current.second]+1;
			}
		}
	}
}

void nojam2178(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&maze[i][j]);	
		}
	}
	//input end
	BFS();
	cout << maze[N-1][M-1];

}

int main(){
	nojam2178();
}
