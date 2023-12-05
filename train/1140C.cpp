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
    vector<pair<int, int>> tb(n);
    for (auto& [a, b] : tb) {
        cin >> b >> a;
        a = -a;
        b = -b;
    }

    sort(tb.begin(), tb.end());

    priority_queue<int> pq;
    i64 ans = 0;
    i64 sum = 0;
    for (auto& [b, t] : tb) {
        ans = max(ans, (sum + t) * b);
        sum += t;
        pq.push(t);
        if (pq.size() >= k) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}