//Chú ý: Mỗi chìa khóa trong N chìa khóa khác sau khi hợp nhất vẫn có thể tiếp tục dùng lại chứ không bị mất đi
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000

int N;
int dist[MAX];
int other_key[MAX];
queue<int> q;

int BFS(int main_key, int lock){
  for(int i=0; i<MAX; i++){
    dist[i] = -1;
  }

  q.push(main_key);
  dist[main_key] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i=0; i<N; i++){
        int v = (u*other_key[i])%100000;
        if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            q.push(v);
        }
        if(v == lock) return dist[v];
    }
  }
  return -1;
}

int main(){
    int main_key, lock;
    cin>>main_key>>lock;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>other_key[i];
    }
    cout<<BFS(main_key, lock);
    return 0;
}
