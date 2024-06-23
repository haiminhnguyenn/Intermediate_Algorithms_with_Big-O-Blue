#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
int V, E;
bool visited[MAX];
int dist[MAX];
vector<int> graph[MAX];
void BFS(int s){
  for(int i=0; i<=V; i++){
    visited[i] = false;
    dist[i] = -1;
  }

  queue<int> q;

  q.push(s);
  visited[s] = true;
  dist[s] = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0; i<graph[u].size(); i++){
      int v = graph[u][i];
      if(!visited[v]){
        q.push(v);
        visited[v] = true;
        dist[v] = dist[u] + 6;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  int case_count;
  cin>>case_count;
  for(int i=0; i<case_count; i++){
    cin>>V>>E;
    int u, v;
    for(int j=0; j<E; j++){
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int s;
    cin>>s;
    BFS(s);
    for(int j=1; j<=V; j++){
      if(j==s) continue;
      else cout<<dist[j]<<" ";
    }
    cout<<endl;
    for(int j=1; j<=V; j++){
      graph[j].clear();
    }
  }
}
