#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
  int n, a, b;
  cin>>n>>a>>b;

  vector<int> h;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    h.push_back(x);
  }

  sort(h.begin(), h.end(), greater<int>());

  int ans = h[a-1] - h[a];
	if(ans==0) cout<<"0";
  else cout<<ans;
}
