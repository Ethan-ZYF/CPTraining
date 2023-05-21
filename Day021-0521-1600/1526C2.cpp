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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    priority_queue<int> pq;
    int ans = 0;
    i64 cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            cur += a[i];
            ans++;
            continue;
        }
        if (cur + a[i] >= 0) {
            cur += a[i];
            pq.push(-a[i]);
            ans++;
            continue;
        }
        if (!pq.empty() && -a[i] < pq.top()) {
            cur += a[i] + pq.top();
            pq.pop();
            pq.push(-a[i]);
        }
    }
    cout << ans << '\n';
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