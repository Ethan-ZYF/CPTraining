#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    if (k > n or k < __builtin_popcount(n)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> a;
    for (int i = 0; i < 30; i++) {
        if (n & (1 << i)) {
            a.push_back(1 << i);
        }
    }
    debug(a);
    priority_queue<int> pq;
    for (auto& x : a) {
        pq.push(x);
    }
    while (pq.size() < k) {
        int x = pq.top();
        pq.pop();
        pq.push(x / 2);
        pq.push(x / 2);
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}