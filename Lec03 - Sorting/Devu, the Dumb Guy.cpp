#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  long long n, x;
  cin>>n>>x;

  vector<long long> c;
  for(int i=0; i<n; i++){
    int y;
    cin>>y;
    c.push_back(y);
  }

  sort(c.begin(), c.end());

  long long ans = 0;
  for (int i=0; i<n; i++){
    ans += c[i]*x;
    if(x>1) x -= 1;
  }

  cout<<ans;
}
