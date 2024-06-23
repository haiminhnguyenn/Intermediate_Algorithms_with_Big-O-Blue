#include <iostream>
#include <queue>
using namespace std;
int main(){
  //Lần lượt nhập vào n từ bàn phím cho đến khi gặp 0 thì dừng
  int n;
  while(true){
    cin>>n;
    if(n == 0) break;

    //Xét TH n =1:
    if (n==1){
      cout<<"Discarded cards:"<<endl;
      cout<<"Remaining card: 1"<<endl;
    }
    //Xét TH n>1:
    else{
    	//Khởi tạo queue lưu trữ các lá bài
    	queue<int> card;
    	for(int i=1; i<=n; i++){
      	card.push(i);
    	}

    	//Thực hiện các thao tác theo yêu cầu để in ra Discarded cards
    	cout<<"Discarded cards: ";
    	while(card.size()>1){
      	cout<<card.front();
      	card.pop();
      	if(card.size()>1) cout<<", ";
      	card.push(card.front());
     	 	card.pop();
    	}
    	cout<<endl;

   		//In ra Remaining card là lá bài còn lại trong queue
    	cout<<"Remaining card: "<<card.front()<<endl;
    }
  }
  return 0;
}
