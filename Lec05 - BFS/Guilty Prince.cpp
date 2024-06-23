#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 20
int W, H;
int dr[] = {-1, 1, 0, 0},
    dc[] = {0, 0, -1, 1};
bool visited[MAX][MAX] = {false};
char maze[MAX][MAX];

struct cell{
    int r, c;
};

//ham kiem tra hop ly
bool isValid(int r, int c){
    if(r>=0 && r<H && c>=0 && c<W) return true;
    return false;
}

//ham BFS
int BFS(cell s){
    int validCellCount = 1;
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
                if(maze[v.r][v.c] == '.' && visited[v.r][v.c] == false){
                    visited[v.r][v.c] = true;
                    validCellCount++;
                    q.push(v);
                }
                else continue;
            }
            else continue;
        }
    }
    return validCellCount;
}
//ham main
int main(){
    int T;
    cin>>T;

    for(int index_case = 1; index_case <= T; index_case++){
        cout<<"Case "<<index_case<<": ";
        cin>>W>>H;

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin>>maze[i][j];
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(maze[i][j] == '@'){
                    cell s;
                    s.r = i;
                    s.c = j;
                    cout<<BFS(s)<<endl;
                }
                else continue;
            }
        }
        memset(visited, false, sizeof(visited));
    }
}
