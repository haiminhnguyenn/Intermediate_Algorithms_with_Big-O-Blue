#include <bits/stdc++.h>
using namespace std;

int main() {
    int numOfQueries;
    cin >> numOfQueries;

    //Khởi tạo pq theo cấu trúc Min-Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    //Vector lưu các phần tử bị xóa khỏi pq
    vector<int> deletedElements;

    while (numOfQueries--) {
        string query;
        cin >> query;

        //Add phần tử vào pq
        if (query == "1") {
            int v;
            cin >> v;
            pq.push(v);
        }

        else if (query == "2") {
            int v;
            cin >> v;

            //Thêm vào vector deletedElements
            deletedElements.push_back(v);
        }

        else if (query == "3") {
            while (true) {
                //Biến kiểm tra phần tử đầu hàng đợi đã bị xóa hay chưa
                bool isDeleted = false;
                for (int i = 0; i < deletedElements.size(); i++) {
                    //Nếu phần tử đầu hàng đợi nằm trong vector bị xóa
                    if (deletedElements[i] == pq.top()) isDeleted = true;
                }

                if (!isDeleted) {
                    cout << pq.top() << endl;
                    break;
                }
                else pq.pop();
            }
        }
    }
}
