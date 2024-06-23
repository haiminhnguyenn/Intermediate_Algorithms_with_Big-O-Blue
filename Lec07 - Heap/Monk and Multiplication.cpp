#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    //Tạo priority queue theo cấu trúc Min-Heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int x;
        //Nhập từng phần tử và push vào pq
        cin >> x;
        pq.push(x);

        if (i < 2) cout << "-1" << endl;
        else if (i == 2) {
            long long max1 = pq.top();
            pq.pop();
            long long max2 = pq.top();
            pq.pop();
            long long max3 = pq.top();
            pq.push(max1);
            pq.push(max2);

            cout << max1 * max2 * max3 << endl;
        }
        else {
            pq.pop();//Xóa phần tử đầu hàng đợi ta còn lại 3 phần tử lớn nhất trong khoảng chỉ số [1,i] nằm trong hàng đợi
            long long max1 = pq.top();
            pq.pop();
            long long max2 = pq.top();
            pq.pop();
            long long max3 = pq.top();
            pq.push(max1);
            pq.push(max2);

            cout << max1 * max2 * max3 << endl;
        }
    }
}
