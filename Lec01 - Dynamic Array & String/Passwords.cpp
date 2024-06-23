#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
  int n, k;
  cin>>n>>k;
  vector<string> pass;
  for(int i=0;i<=n;i++){
   string x;
    cin>>x;
    pass.push_back(x);
  }
  int count_1 = 0, count_2 = 0;
  for(int i =0;i<n;i++)
  {
    if(pass[i].size()<pass[n].size()) count_1++;
    if(pass[i].size()==pass[n].size()) count_2++;
  }
 if((count_1+1)%k==0) cout<<count_1+1+((count_1+1)/k-1)*5<<" ";
  else cout<<count_1+1+((count_1+1)/k)*5<<" ";
  if((count_1+count_2)%k==0) cout<<count_1+count_2+((count_1+count_2)/k-1)*5;
  else cout<<count_1+count_2+((count_1+count_2)/k)*5;
}
