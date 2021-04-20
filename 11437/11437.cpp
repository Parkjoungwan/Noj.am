#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

int t[50001][2];
vector<int> m[50001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(--n){
        int a,b;cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    t[1][0]=t[1][1]=1;
    int q[50000]={1},l=0,r=1;
    while(l!=r){
        int i=q[l++],len=m[i].size();
        f(j,0,len)if(t[m[i][j]][0]==0){
            t[m[i][j]][0]=i;
            t[m[i][j]][1]=t[i][1]+1;
            q[r++]=m[i][j];
        }
    }
    
    int m;cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        if(a==1||b==1) a=1;
        else{
            while(t[a][1]<t[b][1])b=t[b][0];
            while(t[b][1]<t[a][1])a=t[a][0];
            while (a!=b)a=t[a][0],b=t[b][0];
        }
        cout<<a<<'\n';
    }
}
