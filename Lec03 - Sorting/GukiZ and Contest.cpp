#include <iostream>
#include <vector>
using namespace std;
int main(){
  //Nhập số học sinh tham dự
  int n;
  cin>>n;

  //Tạo mảng lưu trữ điểm của các học sinh
  vector<int> score;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    score.push_back(x);
  }

  //Tạo mảng lưu trữ thứ hạng của các học sinh
  vector<int> rank;
  //Ban đầu gán cho tất cả các học sinh đều cùng thứ hạng 1
  for(int i=0; i<n; i++){
    rank.push_back(1);
  }

  /*Với mỗi học sinh thứ i, ta duyệt tất cả các học sinh: Nếu gặp học sinh nào có điểm cao hơn học sinh thứ i đang xét thì tăng thứ hạng của học sinh thứ i lên 1 (rank[i]+1)*/
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(score[j]>score[i]) rank[i]++;
    }
  }

  //In ra thứ hạng của các học sinh
  for(int i=0; i<n; i++){
    cout<<rank[i]<<" ";
  }
  return 0;
}
