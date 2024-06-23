#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  //Tạo 2 mảng để lưu trữ tọa độ 8 điểm nhập vào
  vector<int> x;
  vector<int> y;
  for(int i=0; i<8; i++){
    int a,b;
    cin>>a>>b;
    x.push_back(a);
    y.push_back(b);
  }

  //Khai báo biến ans để kiểm tra tính hợp lệ của 8 điểm nhập vào
  bool ans = true;

  //Kiểm tra tính phân biệt của 8 điểm nhập vào: Nếu 8 điểm nhập vào không phân biệt thì gán ans = false
	for (int i=0; i<8; i++){
   for(int j=i+1; j<8; j++){
     if((x[i]==x[j]) && (y[i]==y[j])) ans = false;
   }
  }

  //Nếu 8 điểm nhập vào phân biệt
  if (ans){
    //gán ans = false
    ans = false;
    //sắp xếp 2 mảng x, y theo thứ tự tăng dần
  	sort(x.begin(), x.end());
  	sort(y.begin(), y.end());
  	//Do 8 điểm nhập vào là phân biệt nên nếu chúng thỏa mãn tính chất dưới đây thì ans = true
  	if((x[0]==x[2]) && (x[2]<x[3]) && (x[3]==x[4]) && (x[4]<x[5]) && (x[5]==x[7])){
    	if((y[0]==y[2]) && (y[2]<y[3]) && (y[3]==y[4]) && (y[4]<y[5]) && (y[5]==y[7])) ans = true;
		}
  }

  if(ans) cout<<"respectable";//Nếu ans = true thì hợp lệ
  else cout<<"ugly";//Nếu ans = false thì không hợp lệ
  return 0;
}
