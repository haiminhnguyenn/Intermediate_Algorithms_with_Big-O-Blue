#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
  //Nhập số nguyên k
  int k;
  cin>>k;
  //Tạo mảng lưu trữ a_i (cm) cây cao lên nếu tháng i được tưới nước
  vector<int> a;
  for(int i=0; i<12; i++){
    int x;
    cin>>x;
    a.push_back(x);
  }

  //Sắp xếp mảng a theo thứ tự giảm dần
  sort(a.begin(), a.end(), greater<int>());

  //Khai báo biến height và ans lần lượt là chiều cao của cây và số cây tối thiểu
  int height = 0, ans = 0;
  /*Nếu chiều cao cây không nhỏ hơn k thì dừng lại. Nếu không thì cộng thêm chiều cao của tháng tiếp theo (sau khi sắ xếp) và tăng số cây tối thiểu thêm 1*/
  for(int i=0; i<12; i++){
    if(height >= k) break;
     height += a[i];
     ans++;
  }

  if(height<k) cout<<"-1";
  else cout<<ans;
}
