#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n_A, n_B, k, m;
  cin>>n_A>>n_B>>k>>m;
  vector<int> A;
  vector<int> B;
  for(int i=0;i<n_A;i++){
    int x;
    cin>>x;
    A.push_back(x);
  }
  for(int i=0;i<n_B;i++){
    int y;
    cin>>y;
    B.push_back(y);
  }
  if(A[k-1]<B[n_B-m]) cout<<"YES";
  else cout<<"NO";
}
