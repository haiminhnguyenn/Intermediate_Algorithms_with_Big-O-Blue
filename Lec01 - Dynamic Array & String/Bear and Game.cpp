#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,x;
  cin>>n;
  vector<int> t;
  for(int i=0;i<n;i++){
    cin>>x;
    t.push_back(x);
  }
  vector<int>::iterator it;
  it = t.begin();
  t.insert(it,0);
  t.push_back(91);
  int check = 0;
  for(int i=0;i<n+1;i++)
  {
    if((t[i+1]-t[i])>15)
    {
      cout<<t[i]+15;
      check ++;
      break;
    }
  }
  if(check==0) cout<<"90";
}
