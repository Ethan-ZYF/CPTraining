#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        cnt[c] += b;
    }
    for (auto& x : a) {
        if (cnt.empty()) break;
        auto [c, b] = *cnt.rbegin();
        if (c > x) {
            cnt[c]--;
            if (cnt[c] == 0) cnt.erase(c);
            x = c;
        }
    }
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
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