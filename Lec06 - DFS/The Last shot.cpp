#include <bits/stdc++.h>
#define MAX 10000 + 5

using namespace std;

int N, M;
bool visited[MAX];//Mảng đánh dấu các đỉnh đã thăm
int maxImpact[MAX];//Mảng lưu tác động gây ra khi kích hoạt các đỉnh
vector<int> graph[MAX];

//Hàm DFS
void DFS(int s){
    memset(visited, false, sizeof(visited));

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
                maxImpact[s]++;
            }
        }
    }
}

//Hàm lấy phần tử lớn nhất trong mảng
int maxElement(int size_arr, int arr[]){
    int max = arr[1];

    for(int i=1; i<=size_arr; i++){
        if(arr[i]>max) max = arr[i];
    }

    return max;
}

int main(){
    //Nhập vào N, M
    cin>>N>>M;

	//Nhập vào đồ thị
    for(int i=0; i<M; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

	//Gán giá trị bàn đầu cho các phần tử trong mảng maxImpact bằng 1
  	for (int i = 1; i <= N; i++) {
        maxImpact[i] = 1;
    }

    //DFS với tất cả các đỉnh trong đồ thị
    for(int i=1; i<=N; i++){
        DFS(i);
    }

    cout<<maxElement(N, maxImpact);
}
