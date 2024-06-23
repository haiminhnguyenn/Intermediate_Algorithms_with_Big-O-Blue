#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
  //Nhập vào kích thước của mảng a
  int n;
  cin>>n;

  //Khởi tạo và nhập vào các phần tử mảng a
  vector<int> a;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    a.push_back(x);
  }

  //Khai báo biến check_sort kiểm tra tính chất đã được sắp xếp theo thứ tự tăng dần của mảng
  bool check_sort = true;

  //Khởi tạo mảng copy_a là bản sao của mảng a
  vector<int> copy_a;
  for(int i=0; i<n; i++){
    copy_a.push_back(a[i]);
  }
  //Sắp xếp mảng copy_a theo thứ tự tăng dần
  sort(copy_a.begin(), copy_a.end());

  //So sánh mảng a với mảng copy_a-là bản sao đã được sắp xếp theo thứ tự tăng dần của a
  for(int i=0; i<n; i++){
    if(copy_a[i] != a[i]) check_sort = false;
  }
  //Nếu mảng a đã được sắp xếp thì output ra yes và vị trí của phần tử đầu tiên trong mảng
  if(check_sort) cout<<"yes"<<endl<<"1 1";
  //Xét trường hợp mảng a chưa được sắp xếp
  else{
    //Khởi tạo mảng need_swap lưu trữ các phần tử liên tiếp của mảng a không tuân theo thứ tự tăng dần
    //Khởi tọa mảng index_need_swap lưu trữ index của phần tử thứ i của a khác với copy_a
  	vector<int> need_swap, index_need_swap;
 	 	for(int i=0; i<n; i++){
    	if(copy_a[i] != a[i]){
      	index_need_swap.push_back(i);
    	}
  	}

  	for(int i = index_need_swap[0]; i <= index_need_swap.back(); i++){
    	need_swap.push_back(a[i]);
  	}

    //Khai báo biến ans để kiểm tra tính chất đã được sắp xếp theo thứ tự giảm dần của mảng need_swap
  	bool ans = true;

    //Khởi tạo mảng copy_need_swap là bản sao của mảng need_swap
  	vector<int> copy_need_swap;
  	for(int i=0; i<need_swap.size(); i++){
    	copy_need_swap.push_back(need_swap[i]);
  	}
  	//Sắp xếp mảng copy_need_swap theo thứ tự giảm dần
  	sort(copy_need_swap.begin(), copy_need_swap.end(), greater<int>());

  	//Kiểm tra tính chất đã được sắp xếp theo thứ tự giảm dần của mảng need_swap
  	for(int i=0; i<need_swap.size(); i++){
    	if(copy_need_swap[i] != need_swap[i]) ans = false;
  	}

    //Nếu mảng need_swap không được sắp xếp theo thứ tự giảm dần thì không đảo ngược được
  	if(ans == false) cout<<"no";
    //Nếu mảng need_swap đã được sắp xếp theo thứ tự giảm dần thì có thể đảo ngược được
  	else cout<<"yes"<<endl<<index_need_swap[0]+1<<" "<<index_need_swap.back()+1;
  }
    return 0;
}
