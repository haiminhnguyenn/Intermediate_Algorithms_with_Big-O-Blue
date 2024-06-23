#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
  //Khai báo và nhập vào n, w
  int n, w;
  cin>>n>>w;

  //Tạo mảng để lưu trữ dung tích a_i của mỗi chén
  vector<int> a;
  for(int i=0; i<(2*n); i++){
    int x;
    cin>>x;
    a.push_back(x);
  }

  //Sắp xếp mảng a theo thứ tự tăng dần
  sort(a.begin(), a.end());
  //Khai báo biến ans (output của bài toán) là tổng lượng nước tối đa mà Pasha có thể rót
  double ans;

  if((2*a[0]) <= a[n]) ans = 3*n*a[0];//ans = a[0]*n + (2*a[0])*n
  else ans = (double) 3*n/2*a[n];//ans = (a[n]:2)*n + a[n]*n

  if(ans > w) ans = w;//Đối chiếu với điều kiện dung tích ấm trà là w

  cout<<fixed<<setprecision(6)<<ans;//In ra ans lấy 6 giá trị thập phân sau giấu phẩy
  return 0;
}
