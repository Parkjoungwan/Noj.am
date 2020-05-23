#include <iostream>
#include <vector>
using namespace std;

#define endl "\n"
#define MAX 501
#define INF 1<<30

struct edge{
  int from;
  int to;
  int cost;
};

int N, M;
long long Dist[MAX];
vector<edge> Edge;


int main() {

  cin >> N >> M;
  for (int i=1; i<=N;i++) Dist[i] = INF;
  for (int i=0; i< M; i++){
    int From, To, Cost;
    edge tmp;
    cin >> tmp.from >> tmp.to >> tmp.cost;

    Edge.push_back(tmp);
  }

  Dist[1] = 0;
  for (int i=1; i<=N - 1; i++){
    for(int j=0; j<Edge.size(); j++){
      int From = Edge[j].from;
      int To = Edge[j].to;
      int Cost = Edge[j].cost;

      if (Dist[From] == INF) continue;
      if (Dist[To] > Dist[From] + Cost) Dist[To] =Dist[From] + Cost;
    }
  }

  for (int i = 0 ; i < Edge.size(); i++){
      int From = Edge[i].from;
      int To = Edge[i].to;
      int Cost = Edge[i].cost;

    if (Dist[From] == INF) continue;
    if (Dist[To] > Dist[From] + Cost){
      cout << -1 << endl;
      exit(0);
    }
  }

  for (int i=2; i<=N; i++){
    if (Dist[i] == INF) cout << -1 << endl;
    else cout << Dist[i]<<endl;
  }

  return 0;
}