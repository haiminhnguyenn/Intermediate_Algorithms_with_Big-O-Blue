#include <iostream>
#include <queue>
using namespace std;
int main(){
  //Khởi tạo biến index_case lưu thứ tự của case bắt đầu từ 1
  int index_case = 1;
  //Tạo vòng lặp while để xử lý các TH
  while(true){
    //Nhập vào p, c
    int p, c;
    cin>>p>>c;
    //Nếu giá trị nhập vào là 0 0 thì dừng
    if(p==0 && c==0) break;

    //In ra TH đang xét
    cout<<"Case "<<index_case<<":"<<endl;

    //Hàng đợi ins để lưu trữ các lệnh
		queue<char> ins;
    //Hàng đợi index để lưu trữ bệnh nhân x cần đưa lên đầu hàng khi gặp lệnh E x
    //Hàng đợi person để lưu trữ STT các bệnh nhân
    //Hàng đợi sub để hỗ trợ thuật toán đưa bệnh nhân x lên đầu hàng
    queue<int> index, person, sub;

    //Nhập lệnh vào hàng đợi ins và index
    for(int i=0; i<c; i++){
      char x;
      cin>>x;
      ins.push(x);
      if(x == 'E'){
        int y;
        cin>>y;
        index.push(y);
      }
    }

    //Nhập bệnh nhân "CẦN XỬ LÝ" vào hàng đợi person
    //Dùng min(p,c) để tối ưu thuật toán do số trường hợp cần xử lý = min(p,c)
    for(int i=1; i<=min(p,c); i++){
      person.push(i);
    }

    //Thực hiện lệnh cho đến khi ngăn xếp ins không còn lệnh để thực hiện
    while(!ins.empty()){
      //Nếu gặp N thì in ra người đứng đầu hàng đợi
      if(ins.front() == 'N'){
        cout<<person.front()<<endl;
        person.push(person.front());
        person.pop();
      }
      //Nếu gặp E x thì đưa người x (ở đầu hàng đợi index) lên đầu hàng đợi person
      else{
        //Dùng hàng đợi sub để lưu lại tất cả các bệnh nhân (ngoại trừ bệnh nhân x) theo đúng thứ tự
        while(!person.empty()){
          if(person.front() != index.front()){
            sub.push(person.front());
            person.pop();
          }
          else person.pop();
        }

        //Nạp bệnh nhân x vào đầu hàng đợi person
        person.push(index.front());
        //Nạp tất cả các bênh nhân trong sub vào person ta sẽ thu được hàng đợi thỏa mãn yêu cầu
        while(!sub.empty()){
          person.push(sub.front());
          sub.pop();
        }
        //Xóa bệnh nhân x được ưu tiên khi thực hiện xong yêu cầu
        index.pop();
      }
      //Xóa lệnh khi thực hiện xong
      ins.pop();
    }
    //Tăng STT lên TH tiếp theo
    index_case++;
  }
}
