#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;

struct Bill {
    int number, price;
};

struct BillAscendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price < b.price;
    }
};

struct BillDescendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price > b.price;
    }
};

int main() {
    int n, k, price, nbills = 0;
    long long money = 0;
    bool taken[MAX] = {false};
    priority_queue<Bill, vector<Bill>, BillAscendingPrice> maxHeap;
    priority_queue<Bill, vector<Bill>, BillDescendingPrice> minHeap;

    cin >> n;

    while (n--) {
        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> price;
            nbills++;
            maxHeap.push((Bill){nbills, price});
            minHeap.push((Bill){nbills, price});
        }

        while (taken[maxHeap.top().number]) {
            maxHeap.pop();
        }

        while (taken[minHeap.top().number]) {
            minHeap.pop();
        }

        money += maxHeap.top().price - minHeap.top().price;
        taken[maxHeap.top().number] = taken[minHeap.top().number] = true;
        maxHeap.pop();
        minHeap.pop();
    }

    cout << money;
    return 0;
}
