#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"
#define MAX 505
#define INF 1<<30

struct edge{
  int from;
  int to;
  int cost;
};

int TC;
int N, M, W;
long long Dist[MAX];
vector<edge> Edge;
int check =0;

void nojam1865(){
  cin >> TC;
  for(int i=0;i<TC;i++){
    cin >> N >> M>> W;
    Edge.clear();
    Edge.resize(N+1);
    check=0;
    for(int i=0;i<M;i++){
      edge tmp;
      cin >> tmp.from >> tmp.to >> tmp.cost;
      Edge.push_back(tmp);
      edge tmp2;
      tmp2.from=tmp.to;
      tmp2.to=tmp.from;
      tmp2.cost=tmp.cost;
      Edge.push_back(tmp2);
    }
    for(int i=0;i<W;i++){
      edge tmp;
      cin >> tmp.from >> tmp.to >> tmp.cost;
      tmp.cost = -tmp.cost;
      Edge.push_back(tmp);
    }
    for(int i=2;i<=N;i++){
      Dist[i]=INF;
    }
    for (int i=1; i<=N; i++){
      for(int z=1; z<=N; z++){
        for(int j=0; j<Edge.size(); j++){
          int From = Edge[j].from;
          int To = Edge[j].to;
          int Cost = Edge[j].cost;

          if (Dist[z]!=INF&&Dist[To] > Dist[From] + Cost) {
            Dist[To] =Dist[From] + Cost;
            if(i==N)check=1; 
          }
        }
      }
   }
    if (check) cout << "Yes"<<endl;
    else cout << "No"<<endl;
  }
}

int main() {
  nojam1865();
}