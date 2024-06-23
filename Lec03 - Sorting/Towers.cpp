#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
  //Khai báo và nhập vào n
  int n;
  cin>>n;

  //Tạo mảng lưu độ dài các thanh
  vector<int> l;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    l.push_back(x);
  }

  //Sắp xếp độ dài các thanh theo thứ tự tăng dần
  sort(l.begin(), l.end());

  //Tạo biến tower_count đếm số tháp tối thiểu và biến match lưu vị trí của phần tử trong mảng l có phần tử tiếp theo khác nó
  int tower_count = 0, match = -1;
  //Tạo mạng tower_height lưu trữ chiều cao các tháp
  vector<int> tower_height;

  /*Thêm phần tử 0 và cuối mảnglđể phục vụ cho vòng for phía dưới luôn trả về kết quả đúng (vì phần tử 0 đảm bảo luôn khác với các phần tử khác trong mảng do mảng là mảng độ dài nên l > 0)*/
  l.push_back(0);
  /*Duyệt mảng l, nếu tìm được phần tử có phần tử tiếp theo khác nó thì tăng tower_count lên 1, lưu số phần tử giống nhau vào mảng tower_height và gán giá trị mới cho match là vị trí i*/
  for(int i = 0; i<n; i++){
    if(l[i] != l[i+1]){
      tower_count++;
      tower_height.push_back(i-match);
      match = i;
    }
  }

  //Sắp xếp mảng tower_height theo thứ tự giảm dần
  sort(tower_height.begin(), tower_height.end(), greater<int>());
  //Biến max_tower_height lưu trữ chiều cao của tháp lớn nhẩt
  int max_tower_height = tower_height[0];

  //In ra màn hình kết quả bài toán
  cout<<max_tower_height<<" "<<tower_count;
  return 0;
}
