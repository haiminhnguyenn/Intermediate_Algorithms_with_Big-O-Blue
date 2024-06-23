#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  int t;
  cin>>t;

  for(int i=1; i<=t; i++){
    string exp;
    cin>>exp;

    stack<char> st;
    for(int i=0; i<exp.size(); i++){
      if(exp[i] == '(') continue;
      else if((exp[i] >= 'a') && (exp[i] <= 'z')) cout<<exp[i];
      else if(exp[i] == ')'){
        cout<<st.top();
        st.pop();
      }
      else st.push(exp[i]);
    }
    cout<<endl;
  }
}
