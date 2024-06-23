#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000 + 5

bool visited[MAX] = {false};
int dist[MAX] = {0};
vector<int> graph[MAX];

//Ham DFS
void DFSRecursion(int s){
    visited[s] = true;
    for(int i=0; i<graph[s].size(); i++){
        int v = graph[s][i];
        if(!visited[v]){
            dist[v] = dist[s] + 1;
            DFSRecursion(v);
        }
    }
}

//Ham main
int main(){
    int N;
    cin>>N;

    for(int i=0; i<N-1; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFSRecursion(1);

    int Q;
    cin>>Q;

    int min_dist = MAX;

    vector<int> girls, id_girlMinDist;
    for(int i=1; i<=Q; i++){
        int x;
        cin>>x;

        girls.push_back(x);
        if(dist[x] < min_dist) min_dist = dist[x];
    }

    for(int i=0; i<girls.size(); i++){
        if(dist[girls[i]] == min_dist) id_girlMinDist.push_back(girls[i]);
    }

    sort(id_girlMinDist.begin(), id_girlMinDist.end());
    cout<<id_girlMinDist[0];
}
