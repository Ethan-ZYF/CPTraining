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
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end(), [&](auto& u, auto& v) {
        return u.second < v.second;
    });
    int ans = 0;
    int last = -1;
    for (auto& [x, y] : a) {
        if (x >= last) {
            ans++;
            last = y;
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