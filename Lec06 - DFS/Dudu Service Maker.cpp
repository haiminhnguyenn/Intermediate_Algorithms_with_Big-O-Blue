#include <bits/stdc++.h>
#define MAX 10000 + 5

using namespace std;

bool visited[MAX];//Mảng lưu trữ các đỉnh đã được thăm
int path[MAX];//Mảng dùng để truy vết đường đi
vector<int> graph[MAX];//Lưu trữ đồ thị dưới dạng danh sách kề

//Hàm kiểm tra có sự tồn tại đường của từ s tới f
bool havePath(int s, int f){
    if(s==f) return true;
    else{
        if(path[f] == -1) return false;
        else{
            return havePath(s, path[f]);
        }
    }
}

//Hàm DFS kiểm tra sự tồn tại của chu trình
bool DFS(int s){
    visited[s] = true;
    stack<int> st;

    st.push(s);

    while(!st.empty()){
        int u = st.top();
        st.pop();

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];

            //Nếu đỉnh v chưa được thăm thì đưa vào ngăn xếp
            if(!visited[v]){
                visited[v] = true;
                st.push(v);
                path[v] = u;
            }

            //Nếu đỉnh v đã được thăm rồi thì kiểm tra xem có sự tồn tại đường đi ngược lại từ v tới u không
            else{
                if(havePath(v, u)){
                    return true;
                }
                else continue;
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin>>T;

    for(int i=0; i<T; i++){
        memset(visited, false, sizeof(visited));//reset lại mảng visited
        memset(path, -1, sizeof(path));//reset lại mảng path

        int N, M;
        cin>>N>>M;

        //Nhập vào đồ thị
        for(int j=0; j<M; j++){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        bool haveCircle = false;//Kiểm tra sự tồn tại của chu trình
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                if(DFS(i)){
                    haveCircle = true;
                    break;
                }
                else continue;
            }
            else continue;
        }

        if(haveCircle) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        //reset lại đồ thị
        for(int j=1; j<=N; j++){
            graph[j].clear();
        }
    }
}
