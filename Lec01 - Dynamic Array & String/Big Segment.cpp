#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> l, r;
  for(int i=0; i<n;i++){
    int x,y;
    cin>>x>>y;
   	l.push_back(x);
    r.push_back(y);
  }

  int min = l[0], max=r[0];
  for(int i=0;i<n;i++){
    if(l[i]<min) min = l[i];
    if(r[i]>max) max = r[i];
  }

  int bol = false;
  for (int i=0; i<n; i++){
    if (l[i]==min && r[i]==max){
      bol = true;
      cout<<i+1;
    }
  }
  if(bol == false) cout<<"-1";
}
