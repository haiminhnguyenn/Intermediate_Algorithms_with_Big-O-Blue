#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int solve() {
    long long total = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        //a + b là chi phí nhỏ nhất của 2 phần tử tiếp theo được thêm vào
        total += a + b;
        //Tiếp tục push chi phí mới nhận vào hàng đợi ưu tiên
        pq.push(a+b);
    }

    cout << total << endl;
    pq.pop();
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }

        solve();
    }
}
