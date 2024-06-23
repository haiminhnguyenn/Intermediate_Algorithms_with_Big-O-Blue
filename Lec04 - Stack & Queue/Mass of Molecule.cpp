#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  //Nhập vào công thức phân tử
  string mol;
  cin>>mol;

  //Tạo ngăn xếp phục vụ tính toán KLPT
  stack<int> st;

  //Duyệt từng ký tự của CTPT
  for(int i=0; i<mol.size(); i++){
    //Nếu gặp C, H, O thì nạp KL của các ng.tố đó vào ngăn xếp
    if(mol[i]=='C') st.push(12);
    else if(mol[i]=='H') st.push(1);
    else if(mol[i]=='O') st.push(16);
    //Nếu gặp '(' thì nạp vào ngăn xếp dưới dạng -1 (phù hợp kiểu int của ngăn xếp) để đánh dấu
    else if(mol[i]=='(') st.push(-1);
    //Nếu gặp số
    else if(mol[i]>='2' && mol[i]<='9'){
      //Đổi số tự kiểu string về int
      //Ngoài ra có thể dùng num = mol[i] -'0' để chuyển đổi
      int num = atoi(&mol[i]);
      //Nạp giá trị sau khi nhân vào ngăn xếp
      int pro = num*st.top();
      st.pop();
      st.push(pro);
    }
    //Nếu gặp ')' thì cộng tất cả các phần tử phía trên ngăn xếp cho đến khi gặp dấu đóng ngoặc (-1) thì dừng
    //Nạp kết quả vừa tính được vào ngăn xếp
    else if(mol[i]==')'){
      int res = 0;
      while(st.top() != -1){
        res += st.top();
        st.pop();
      }
			st.pop();
      st.push(res);
    }
  }

  //ans lưu kết quả
  int ans = 0;
  //Cộng tất cả các phần tử trong ngăn xếp lại
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }

  //output
	cout<<ans;
}
