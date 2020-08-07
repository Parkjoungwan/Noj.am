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
	int rrow = (int)row-64;
	int rrow2 = (int)row2-64;
	if(mv=="R"){
		if(rrow<8){
			//cout << "OUT: R\n";
			rrow++;
		}else{
			return;
		}
		if(same()){
			if(rrow2<8){
				rrow2++;
			}else{
				rrow--;
			}
		}
		return;
	}
	else if(mv=="L"){
		if(rrow>1){
			//cout << "row:" << rrow<<endl;
			rrow--;
			//cout << "out: L\n";
		}else{
			return;
		}
		if(same()){
			if(rrow2>1){
				rrow2--;
			}else{
				rrow++;
			}
		}
		return;
	}
	else if(mv=="T"){
		if(low<8){
			low++;
			//cout << "out: T\n";
		}else{
			return;
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
	else if(mv=="B"){
		if(low>1){
			low--;
			//cout << "out: B\n";
		}else{
			return;
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
	else if(mv=="RT"){
		if(rrow<8&&low<8){
			rrow++;
			low++;
			//cout << "out : RT\n";
		}else{
			return;
		}
		if(same()){
			if(low2<8&&rrow2<8){
				rrow2++;
				low2++;
			}else{
				rrow--;
				low--;
			}
		}
		return;
	}
	else if(mv=="RB"){
		if(rrow<8&&low>1){
			rrow++;
			low--;
			//cout << "out: RB\n";
		}else{
			return;
		}
		if(same()){
			if(rrow2<8&&low2>1){
				rrow2++;
				low2--;
			}else{
				rrow--;
				low++;
			}
		}
		return;
	}
	else if(mv=="LT"){
		if(rrow>1&&low<8){
			rrow--;
			low++;
			//cout << "out: LT\n";
		}else{
			return;
		}
		if(same()){
			if(rrow2>1&&low2<8){
				rrow2--;
				low2++;
			}else{
				rrow++;
				low--;
			}
		}
		return;
	}
	else if(mv=="LB"){
		if(rrow>1&&low>1){
			row--;
			low--;
			//cout << "out: LB\n";
		}else{
			return;
		}
		if(same()){
			if(rrow2>1&&low2>1){
				rrow2--;
				low2--;
			}else{
				return;
			}
		}
		return;
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
	stone[1]=low2;
	
	//cout << "입력끝"<<"\n";

	//명령어 갯수
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		string command;
		cin >> command;
		move(command);
	}
	char kingchar = (char)(king[0]+64);
	char stonechar = (char)(stone[0]+64);

	cout << kingchar << king[1] << endl;
	cout << stonechar << stone[1] << endl;
}

int main(){
	nojam1063();
}
