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
    i64 t;
    cin >> n >> t;
    vector<i64> a(n), ps(n + 1);
    for (auto& x : a) cin >> x;
    i64 ans = 0;
    while (t) {
        i64 cnt = 0, cost = 0;
        for (int i = 0; i < n; i++) {
            if (cost + a[i] > t) continue;
            cost += a[i];
            cnt++;
        }
        if (cnt == 0) break;
        ans += t / cost * cnt;
        t %= cost;
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