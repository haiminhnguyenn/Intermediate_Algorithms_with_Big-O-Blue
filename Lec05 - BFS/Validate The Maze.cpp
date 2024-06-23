#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 20
int m, n;
int dr[] = {-1, 1, 0, 0},
    dc[] = {0, 0, -1, 1};
bool visited[MAX][MAX] = {false};
char maze[MAX][MAX];

struct cell{
    int r, c;
};

//Ham kiem tra thuoc bien
bool isEdge(int r, int c){
    if(r==0 || r==m-1 || c==0 || c==n-1) return true;
    return false;
}

//Ham kiem tra thuoc ma tran hop le
bool isValid(int r, int c){
    if(r>=0 && r<m && c>=0 && c<n) return true;
    return false;
}

//BFS
void BFS(cell s){
    queue<cell> q;
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
                if(maze[v.r][v.c]=='.' && visited[v.r][v.c]==false){
                    visited[v.r][v.c] = true;
                    q.push(v);
                }
                else continue;
            }
            else continue;
        }
    }
}

//Ham main
int main(){
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cin>>m>>n;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>maze[i][j];
            }
        }

        vector<cell> openings;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isEdge(i, j)==true && maze[i][j]=='.'){
                    cell tmp;
                    tmp.r = i;
                    tmp.c = j;
                    openings.push_back(tmp);
                }
                else continue;
            }
        }

        if(openings.size() != 2) cout<<"invalid"<<endl;
        else{
            BFS(openings[0]);
            if(visited[openings[1].r][openings[1].c]) cout<<"valid"<<endl;
            else cout<<"invalid"<<endl;
        }
        memset(visited, false, sizeof(visited));
    }
}
