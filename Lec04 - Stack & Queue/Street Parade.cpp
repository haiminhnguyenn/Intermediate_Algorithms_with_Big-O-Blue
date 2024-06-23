#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int main(){
  while(true){
    //Nhập vào n xe tải trang trí
    int n;
    cin>>n;
    //Nếu n được nhập vào bằng 0 thì dừng
    if(n == 0) break;

    //Khởi tạo hàng đợi truck lưu trữ n chiếc xe tải
    queue<int> truck;
    for(int i=0; i<n; i++){
      int x;
      cin>>x;
      truck.push(x);
    }

		//Ngăn xếp sub_street lưu trữ những chiếc xe đi vào đường phụ
    stack<int> sub_street;

    //Tạo biến ans để kiểm tra xem có sắp xếp được đối với trường hợp đang thử nghiệm hay không
    bool ans = true;

    //Tạo biến j để phục vụ cho vòng lặp while phía dưới
    int j = 1;
    //Duyệt tìm các chiếc xe theo thứ tự từ 1 cho đến n để cho ra
    while(j<=n){
      //Tìm chiếc xe thứ j (j chạy từ 1 cho đến n) để cho ra ngoài
      //Nếu ngăn xếp truck không rỗng
      if(truck.empty() == false){
        //Kiểm tra phần tử đầu tiên của ngăn xếp có phải là xe thứ j cần tìm không
        //Nếu có
        if(truck.front()==j){
          //Cho phần tử cần tìm ra ngoài (xóa)
          truck.pop();
          //Tăng j lên để tìm chiếc xe tiếp theo cần cho ra ngoài
          j++;
        }
        //Nếu không
        //Kiểm tra: nếu đường phụ rỗng hoặc xe trên cùng của đường phụ không phải xe thứ j cần tìm
        else if((sub_street.empty() == true) || (sub_street.top() != j)){
           //Nạp phần tử đầu tiên của truck vào đường phụ
           sub_street.push(truck.front());
           truck.pop();
        }
        //Kiểm tra: Nếu xe trên cùng của đường phụ là xe thứ j cần tìm
        else{
          	//Xóa xe cần tìm đi
            sub_street.pop();
          	//Tăng j lên để tìm xe tiếp theo
            j++;
        }
      }
      //Nếu truck rỗng: ta chỉ xét đường phụ
      else{
        //Nếu đường phụ rỗng hoặc xe trên cùng của đường phụ không phải xe cần tìm
        if((sub_street.top() != j) || (sub_street.empty() == true )){
          	//Không thể sắp xếp các xe theo thứ tự
          	ans = false;
          	//Thoát khỏi vòng lặp khi tìm ra kết quả
        		break;
        }
        //Nếu xe trên cùng của đường phụ là xe cần tìm
        else{
          	//Xóa nó đi
            sub_street.pop();
          	//Tăng j lên để tìm xe tiếp theo
            j++;
        }
      }
    }

    if(ans) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
