#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x : a)
        cin >> x;
    for (int& x : b)
        cin >> x;
    priority_queue<int> q1, q2;
    for (auto x : a)
        q1.push(x);
    for (auto x : b)
        q2.push(x);
    int ans = 0;
    while (!q1.empty() and !q2.empty()) {
        int x = q1.top();
        int y = q2.top();
        if (x == y) {
            q1.pop();
            q2.pop();
        } else if (x < y) {
            q2.pop();
            q2.push(to_string(y).size());
            ans++;
        } else {
            q1.pop();
            q1.push(to_string(x).size());
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}