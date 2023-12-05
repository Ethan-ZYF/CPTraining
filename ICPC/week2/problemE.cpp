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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    map<i64, int> s;
    for (int i = 0; i < n; i++) {
        i64 x = a[i];
        int idx = i;
        while (s.count(x)) {
            int j = s[x];
            s.erase(x);
            x *= 2;
            idx = max(idx, j);
        }
        s[x] = idx;
    }
    vector<pair<int, i64>> ans;
    for (auto [x, i] : s) ans.emplace_back(i, x);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [i, x] : ans) cout << x << ' ';
    cout << '\n';
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