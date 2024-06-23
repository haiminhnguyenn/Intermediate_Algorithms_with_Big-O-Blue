#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  vector<int> nutao;
  cin>>n;
  for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nutao.push_back(x);
  }
  if(n==1&&nutao[0]==1) cout<<"YES";
  if(n==1&&nutao[0]==0) cout<<"NO";
  if(n>1){
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(nutao[i]==1) count++;
  }
  if(count==(n-1)) cout<<"YES";
  else cout<<"NO";}
}
