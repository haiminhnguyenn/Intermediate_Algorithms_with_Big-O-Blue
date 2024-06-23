#include <iostream>
#include <queue>
using namespace std;
#define MAX 500 + 5
int n, m;
int dr[] = {-1, 1, 0, 0},
    dc[] = {0, 0, -1, 1};
char maze[MAX][MAX];


struct cell{
    int r, c;
};

//Ham kiem tra hop le
bool isValid(int r, int c){
    if(r>=1 && r<=n && c>=1 && c<=m) return true;
    return false;
}

//Ham BFS
void BFS(cell s){
    queue<cell> q;
    q.push(s);

    while(!q.empty()){
        cell u = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            cell v;
            v.r = u.r + dr[i];
            v.c = u.c + dc[i];

            if(isValid(v.r, v.c)){
                if(maze[v.r][v.c] == 'X'){
                    maze[v.r][v.c] = '0';
                }
                else if(maze[v.r][v.c] == '.'){
                    maze[v.r][v.c] = 'X';
                    q.push(v);
                }
                else continue;
            }
            else continue;
        }
    }
}

//main
int main(){
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>maze[i][j];
        }
    }

    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;

    cell s;
    s.r = r1;
    s.c = c1;
    BFS(s);

    if(maze[r2][c2] == '0') cout<<"YES";
    else cout<<"NO";
    return 0;
}
