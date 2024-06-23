#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 250
int N, M;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool visited[MAX][MAX] = {false};
int table[MAX][MAX];
int count_slicks[MAX*MAX] = {0};

struct cell{
    int r, c;
};
//Ham kiem tra hop le
bool isValid(int r, int c){
    if(r>=0 && r<N && c>=0 && c<M) return true;
    return false;
}

//Ham BFS
int BFS(cell s){
    int size_slick = 1;
    queue <cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    while(!q.empty()){
        cell u = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            cell v;
            v.r = u.r + dr[i];
            v.c = u.c + dc[i];
            if(isValid(v.r, v.c)){
                if(table[v.r][v.c]==1 && visited[v.r][v.c]==false){
                    visited[v.r][v.c] = true;
                    q.push(v);
                    size_slick += 1;
                }
            }
        }
    }
    return size_slick;
}

//Ham main
int main(){
    while(true){
        cin>>N>>M;
        if(N==0 && M==0) break;

        int slicks_count_total = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>table[i][j];
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(table[i][j]==1 && visited[i][j]==false){
                    cell s;
                    s.r = i;
                    s.c = j;
                    int tmp = BFS(s);
                    count_slicks[tmp]++;
                    slicks_count_total++;
                }
                else continue;
            }
        }

        cout<<slicks_count_total<<endl;
        for(int i=0; i<MAX*MAX; i++){
            if(count_slicks[i]>0){
                cout<<i<<" "<<count_slicks[i]<<endl;
            }
        }

        memset(visited, false, sizeof(visited));
        memset(count_slicks, 0, sizeof(count_slicks));
    }
}
