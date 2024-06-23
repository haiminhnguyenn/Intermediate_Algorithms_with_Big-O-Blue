#include <bits/stdc++.h>
using namespace std;

int main() {
    // n: số lượng thao tác cần thực hiện
    // x: điểm xếp hạng của bài đánh giá mới
    // nreviews: tổng số bài đánh giá
    int n, x, nreviews = 0;
    string type; // Biến để nhập vào thao tác
    priority_queue<int> maxHeap; // Lưu top các đánh giá tích cực
    priority_queue<int, vector<int>, greater<int>> minHeap; // Lưu các đánh giá còn lại

    cin >> n;

    while (n--) {
        cin >> type;

        if (type == "1") {
            cin >> x;
            nreviews++;

            if (minHeap.empty()) maxHeap.push(x);
            else {
                // Nếu x > đánh giá có số điểm thấp nhất trong top thì cập nhật lại hàng đợi
                if (x > minHeap.top()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
                else maxHeap.push(x);
            }

            // Số đánh giá tăng đến khi chia hết cho 3 thì số đánh giá trong top tăng lên 1
            if (nreviews % 3 == 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        if (type == "2") {
            if (minHeap.empty()) cout << "No reviews yet" << endl;
            else cout << minHeap.top() << endl;
        }
    }

    return 0;
}
