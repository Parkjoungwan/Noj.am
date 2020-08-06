#include <iostream>
#include <string>
using namespace std;
int T;
char row,row2;
int low,low2;
int king[2];
int stone[2];

bool same(){
	if(row==row2 && low==low2){
		return true;
	}
	return false;
}


void move(string mv){
	if(mv=="R"){
		if(low<8){
			low++;
		}
		if(same()){
			if(low2<8){
				low2++;
			}else{
				low--;
			}
		}
		return;
	}
	if(mv=="L"){
		if(low>1){
			low--;
		}
		if(same()){
			if(low2>1){
				low2--;
			}else{
				low++;
			}
		}
		return;
		
	}
	if(mv=="B"){
		if(row>1){
			row--;
		}
		if(same()){
			if(row2>1){
				row2--;
			}else{
				row++;
			}
		}
		return;
	}
	if(mv=="T"){
		if(row<8){
			row++;
		}
		if(same()){
			if(row<8){
				row2++;
			}else{
				row--;
			}
		}
		return;
	}
	if(mv=="RT"){
		if(row<8||low<8){
			row++;
			low++;
		}
		if(same()){
			if(row<8||low<8){
				row2++;
				low2++;
			}else{
				row--;
				low--;
			}
		}
	}

}

void nojam1063(){
	//king 위치
	scanf(" %1c",&row);
	scanf("%1d",&low);
	king[0]=(int)row - 64;
	king[1]=low;

	//stone 위치
	scanf(" %1c",&row2);
	scanf("%1d",&low2);
	stone[0]=(int)row2-64;
	stone[1]=low;
	
	cout << "입력끝"<<"\n";

	//명령어 갯수
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		string command;
		cin >> command;
		move(command);
	}	

}

int main(){
	nojam1063();
}
