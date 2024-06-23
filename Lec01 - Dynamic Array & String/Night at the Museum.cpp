#include <iostream>
#include <string>
using namespace std;
int main(){
  string name;
  cin>> name;
  name.insert(0, "a");
  int sum = 0;
  for(int i=0;i<name.size()-1;i++)
  {
    int compare_1 = abs((int) name[i+1] - name[i]);
    int compare_2 = (int) 26 - compare_1;
    sum += min(compare_1, compare_2);
  }
  cout<<sum;
  return 0;
}
