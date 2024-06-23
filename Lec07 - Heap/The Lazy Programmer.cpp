#include <bits/stdc++.h>
using namespace std;

struct Job {
    int a, b, d;

    bool operator<(const Job &other) const {
        return a < other.a;
    }
};

bool wayToSort(const Job &a, const Job &b) {
    return a.d < b.d;
}

int main() {
    int t, n, time;
    double sumMoney;
    cin >> t;

    while (t--) {
        cin >> n;

        time = 0; sumMoney = 0;
        vector<Job> job;
        priority_queue<Job> pq;

        for (int i = 0; i < n; i++) {
            Job x;
            cin >> x.a >> x.b >> x.d;
            job.push_back(x);
        }

        sort(job.begin(), job.end(), wayToSort);

        for (int i = 0; i < n; i++) {
            pq.push(job[i]);
            time += job[i].b;

            while (time > job[i].d) {
                Job top = pq.top();
                pq.pop();

                if (top.b > (time - job[i].d)) {
                    sumMoney += (double) (time - job[i].d) / top.a;
                    top.b -= time - job[i].d;
                    pq.push(top);
                    time = job[i].d;
                }
                else {
                    sumMoney += (double) top.b / top.a;
                    time -= top.b;
                    top.b = 0;
                }
            }
        }

        cout << fixed << setprecision(2) << sumMoney << endl;
    }

    return 0;
}
