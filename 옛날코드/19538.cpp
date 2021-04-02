#include <iostream>
using namespace std;

int N;

void reset(int *set){
	for(int i=0;i<N;i++){
		set[i]=-1;
	}
}

void nojam19538(){
	//연결관계
	cin >> N;
	int** Per = new int*[N];
	for(int i=0;i<N;i++){
		Per[i] = new int [1000000];
	}
	int input;
	for(int i=0;i<N;i++){
		input=-1;
		for(int j=0;input!=0;j++){
			cin >> Per[i][j];
			input = Per[i][j];
		}
	}

	//시작지점
	int speaker;
	cin >> speaker;
	int* start = new int (speaker);
	for(int i=0; i<speaker;i++){
		cin >> start[i];
	}

	//믿는 사람
	int *bel = new int[N+1];
	reset(bel);
	for(int i=1;i<speaker;i++){
		bel[start[i]]=0;
	}
	
	//전파시작
	int infect=0;
	int uninfect=0;
	int second=1;
	int last =speaker;
	int now =0;
	while(1){
		for(int i=0;i<N;i++){
			for(int j=0;Per[i][j]!=0;j++){
				if(bel[Per[i][j]]!=-1){
					infect++;		
				}else{
					uninfect++;
				}
			}
			if(infect>=uninfect){
				cout << i<<": infected!\n";
				bel[i]=second;
			}
			infect=0;
			uninfect=0;
		}
		for(int i=1;i<=N;i++){
			if(bel[i]!=-1){
				now++;
			}
		}
		if(last==now) break;
		last=now;
		second++;
	}
	
	for(int i=0;i<N;i++){
		cout << bel[i];
	}
}

int main(){
	nojam19538();
}
