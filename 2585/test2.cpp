#include<iostream>
#include<cstring>
#define DIST(a,b,c,d) ((a-c)*(a-c)+(b-d)*(b-d))
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
 
int a[1001][2]={{0,0}},n,k,lim,z[1001];
 
bool possible(int i,int cnt){
    if(cnt<1)return false;
    z[i]=1;
    f(j,1,n)if((!z[j]&&DIST(a[i][0],a[i][1],a[j][0],a[j][1])<=lim)&&
               (DIST(a[j][0],a[j][1],10000,10000)<=lim||possible(j,cnt-1)))return true;
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    
    f(i,1,n)cin>>a[i][0]>>a[i][1];
    
    int l=1,r=15000;
    while(l<=r){
        memset(z,0,sizeof(z));
        int mid=(l+r)/2;
        lim=mid*mid*100;
        if(possible(0, k))r=mid-1;
        else l=mid+1;
    }
    cout<<l;
}
