#include <iostream>
#include <string>
using namespace std;
int main(){
  string s, t;
  cin>>s>>t; //Nhập vào hai chuỗi s và t.

  bool need_tree = false, automaton = false, array = false;//Khai báo các thuộc tính và gán giá trị false.

  int sCount[26] = {0}, tCount[26] = {0};//Khai báo hai mảng đếm số các ký tự từ a đến z của s và t;

  for (int i=0; i<s.size();i++){
    sCount[s[i]-'a']++;
  }//Đếm các ký tự xuất hiện trong chuỗi s và nhập và mảng sCount[];
  for (int i=0; i<t.size();i++){
    tCount[t[i]-'a']++;
  }//Đếm các ký tự xuất hiện trong chuỗi t và nhập và mảng tCount[];

  for (int i = 0;i<26;i++){
    if(sCount[i]<tCount[i]) need_tree = true;//need tree đúng
    if(sCount[i]>tCount[i]) automaton = true;//automation đúng
  }

  int index_found = 0, match = -1;
  /*Khai báo biến index_found để tìm vị trí đầu tiên của từng ký tự của chuỗi t trong chuỗi s sau vị trí match
  biến match để lưu trữ vị trí ký tự hiện tại đang xét của chuỗi t trong chuỗi s */
  for (int i=0; i < t.size(); i++){
    index_found = s.find_first_of(t[i],match+1);
    //Gán index_found bởi vị trí đầu tiên của t[i] trong chuỗi s kể từ vị trí match + 1 trở đi
    if(index_found > match) match = index_found;
    //Nếu tìm được vị trí của t[i] sau vị trí match trong s thì gán match bởi vị trí mới tìm được
    else array = true;
    //Nếu không tìm được vị trí của t[i] sau vị trí match trong s thì cần array
  }
    if(need_tree) cout<<"need tree";//xảy ra need tree
    else if(automaton && array) cout<<"both";//xảy ra both
    else if(automaton) cout<<"automaton";//xảy ra automation
    else if(array) cout<<"array"; //xảy ra array
}
