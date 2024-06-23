#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, type, x;
    bool isStack, isQueue, isPriorityQueue;

    while (cin >> n) {
        isStack = true, isQueue = true, isPriorityQueue = true;
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;

        while (n--) {
            cin >> type >> x;

            if (type == 1) {
                st.push(x);
                q.push(x);
                pq.push(x);
            }

            if (type == 2) {
                if (st.empty()) {
                    isStack = isQueue = isPriorityQueue = false;
                    continue;
                }
                if (x != st.top()) isStack = false;
                st.pop();
                if (x != q.front()) isQueue = false;
                q.pop();
                if (x != pq.top()) isPriorityQueue = false;
                pq.pop();
            }
        }

        if (isStack + isQueue + isPriorityQueue == 0) cout << "impossible" << endl;
        else if (isStack + isQueue + isPriorityQueue > 1) cout << "not sure" << endl;
        else if (isStack) cout << "stack" << endl;
        else if (isQueue) cout << "queue" << endl;
        else if (isPriorityQueue) cout << "priority queue" << endl;
    }
}
