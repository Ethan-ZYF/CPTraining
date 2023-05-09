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
    vector<i64> a(n), pref(n);
    for (auto& x : a) cin >> x;
    i64 cur = 0;
    int ans = 0;
    set<i64> s = {0};
    for (auto& x : a) {
        cur += x;
        if (s.count(cur)) {
            ans++;
            s.clear();
            s.insert(0);
            cur = x;
        }
        s.insert(cur);
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