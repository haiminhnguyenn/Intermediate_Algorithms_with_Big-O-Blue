#include <bits/stdc++.h>
using namespace std;

struct Topic {
    int id;
    long long oldScore, newScore, change;

    Topic(int _id, long long _oldScore, long long _newScore) {
        id = _id;
        oldScore = _oldScore;
        newScore = _newScore;
        change = _newScore - oldScore;
    }

    bool operator<(const Topic &other) const {
        return (change < other.change) || (change == other.change && id < other.id);
    }
};

int main() {
    int n;
    cin >> n;

    int id;
    long long oldScore, posts, likes, comments, shares;
    priority_queue<Topic> pq;

    while (n--) {
        cin >> id >> oldScore >> posts >> likes >> comments >> shares;
        long long newScore = 50 * posts + 5 * likes + 10 * comments + 20 * shares;
        pq.push(Topic(id, oldScore, newScore));
    }

    for (int i = 0; i < 5; i++) {
        Topic topic = pq.top();
        pq.pop();
        cout << topic.id << " " << topic.newScore << endl;
    }

    return 0;
}
