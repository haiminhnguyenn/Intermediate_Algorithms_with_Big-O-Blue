#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 100000 + 5
long long N;
bool visited[MAX] = {false};
vector<long long> graph[MAX];

//DFS
void DFS(int s){
    stack<int> st;
    visited[s] = true;
    st.push(s);
    while(!st.empty()){
        int u = st.top();
        st.pop();

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];

            if(!visited[v]){
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

//main
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>N;
        long long e;
        cin>>e;

        for(int i=0; i<e; i++){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        long long connect_count = 0;

        for(int i=0; i<N; i++){
            if(!visited[i]){
                connect_count += 1;
                DFS(i);
            }
            else continue;
        }

        cout<<connect_count<<endl;

        for(int i=0; i<N; i++){
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
}
