#include <iostream>
#include <queue>
using namespace std;
#define MAX 250
int N, M;
int dr[] = {-1, 1, 0, 0},
    dc[] = {0, 0, -1, 1};
int surviveSheepCount = 0,
    surviveWolfCount = 0;
bool visited[MAX][MAX] = {false};
char maze[MAX][MAX];

struct field{
    int r, c;
};

//Hàm kiểm tra ô có thuộc ma trận không
bool isValid(int r, int c){
    if(r>=0 && r<N && c>=0 && c<M) return true;
    return false;
}
//Hàm kiểm tra ô có thuộc biên không
bool isEdge(int r, int c){
    if(r==0 || r==N-1 || c==0 || c==M-1) return true;
    return false;
}

//Hàm BFS
void BFS(field s){
    bool isUnknownFields = false;
    int sheep_count = 0,
        wolf_count = 0;
    queue<field> q;
    visited[s.r][s.c] = true;
    if(maze[s.r][s.c]=='k') sheep_count++;
    else if(maze[s.r][s.c]=='v') wolf_count++;
    if(isEdge(s.r, s.c)) isUnknownFields = true;
    q.push(s);
    while(!q.empty()){
        field u = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            field v;
            v.r = u.r + dr[i];
            v.c = u.c + dc[i];

            if(isValid(v.r, v.c)){
                if(maze[v.r][v.c]!='#' && visited[v.r][v.c]==false){
                    if(isEdge(v.r, v.c)) isUnknownFields = true;
                    visited[v.r][v.c] = true;
                    if(maze[v.r][v.c]=='k') sheep_count++;
                    else if(maze[v.r][v.c]=='v') wolf_count++;
                    q.push(v);
                }
            }
        }
    }
    if(isUnknownFields){
        surviveSheepCount += sheep_count;
        surviveWolfCount += wolf_count;
    }
    else{
        if(sheep_count > wolf_count) surviveSheepCount += sheep_count;
        else surviveWolfCount += wolf_count;
    }
}

//Hàm main
int main(){
    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>maze[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maze[i][j]!='#' && visited[i][j]==false){
                field s;
                s.r = i;
                s.c = j;
                BFS(s);
            }
        }
    }

    cout<<surviveSheepCount<<" "<<surviveWolfCount;
}
