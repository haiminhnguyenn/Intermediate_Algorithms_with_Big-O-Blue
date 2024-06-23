#include <bits/stdc++.h>
using namespace std;
#define MAX 50 + 5

int n, m;
int dr[] = {-1, 1, 0, 0},
    dc[] = {0, 0, -1, 1};
int lakes_count = 0;
int lakesSizeFromCell[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
bool changed[MAX][MAX] = {false};

char maze[MAX][MAX];
vector<int> lakes_size;

struct cell{
    int r, c;
};

bool isValid(int r, int c){
    if(r>=0 && r<n && c>=0 && c<m) return true;
    return false;
}

bool isEdge(int r, int c){
    if(r==0 || r==n-1 || c==0 || c==m-1) return true;
    return false;
}

void DFS(cell s){
    //cout << s.r << ' ' << s.c << '\n';
    stack<cell> st;
    visited[s.r][s.c] = true;
    st.push(s);

    bool isConnectedWithOcean = false;
    int sizeOfLake = 1;

    while(!st.empty()){
        cell u = st.top();
        st.pop();
        if(isEdge(u.r, u.c)) isConnectedWithOcean = true;

        for(int i=0; i<4; i++){
            cell v;
            v.r = u.r + dr[i];
            v.c = u.c + dc[i];

            if(isValid(v.r, v.c) && maze[v.r][v.c]=='.' && visited[v.r][v.c]==false){
                visited[v.r][v.c] = true;
                sizeOfLake += 1;
                st.push(v);
            }
        }
    }

    if(!isConnectedWithOcean){
        lakes_size.push_back(sizeOfLake);
        lakesSizeFromCell[s.r][s.c] = sizeOfLake;
        lakes_count++;
    }

}

void DFStoPrintChangedMap(cell s){
    stack<cell> st;
    changed[s.r][s.c] = true;
    maze[s.r][s.c] = '*';
    st.push(s);

    while(!st.empty()){
        cell u = st.top();
        st.pop();

        for(int i=0; i<4; i++){
            cell v;
            v.r = u.r + dr[i];
            v.c = u.c + dc[i];

            if(isValid(v.r, v.c)){
                if(maze[v.r][v.c]=='.' && changed[v.r][v.c]==false){
                    changed[v.r][v.c] = true;
                    maze[v.r][v.c] = '*';
                    st.push(v);
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    int k;
    cin>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j]=='.' && visited[i][j]==false){
                cell s;
                s.r = i;
                s.c = j;
                DFS(s);
            }
        }
    }

    sort(lakes_size.begin(), lakes_size.end());

    int lakesNeedDelete_count = lakes_count - k;
    //cout << lakes_count << '\n';
    int ans = 0;
    for(int i=0; i<lakesNeedDelete_count; i++){
        ans += lakes_size[i];
    }

    cout<<ans<<endl;
    for(int i=0; i<lakesNeedDelete_count; i++){
        bool deleted = false;
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(lakesSizeFromCell[j][k]==lakes_size[i] && changed[j][k]==false){
                    cell s;
                    s.r = j;
                    s.c = k;
                    DFStoPrintChangedMap(s);
                    deleted = true;
                    break;
                }
            }
            if(deleted) break;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<maze[i][j];
        }
        cout << '\n';
    }
}
