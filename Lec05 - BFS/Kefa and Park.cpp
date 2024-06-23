#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000000
bool visited[MAX];
int cat[MAX], avail_restaurants = 0;
int a[MAX];
vector<int> graph[MAX];
queue<int> q;
int n, m;

int BFS(int s){
  for(int i=0; i<=n; i++){
    visited[i] = false;
    cat[i] = 0;
  }

  visited[s] = true;
  if(a[s] == 1) cat[s] = 1;
  q.push(s);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i = 0; i<graph[u].size(); i++){
      int v = graph[u][i];

      if(!visited[v]){
        visited[v] = true;

        if(a[v] == 1) cat[v] = cat[u] + 1;
        if(cat[v] <= m){
            if(graph[v].size() == 1) avail_restaurants++;
            else q.push(v);
        }
      }
    }
  }
  return avail_restaurants;
}

int main(){
  cin>>n>>m;
  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  for(int i=0; i<n-1; i++){
    int x, y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  cout<<BFS(1);
}
