#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n;
    cin >> n;
    auto check = [&](i64 x) -> bool {
        return x * (x + 1) * (x + 2) / 6 >= n;
    };
    i64 l = 0, r = 1e6;
    while (r - l > 1) {
        i64 mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    debug(r);
    i64 x = r;
    cout << x << '\n';
    i64 remain = n;
    vector<i64> ans;
    for (i64 i = 1; i <= x; i++) {
        i64 days = x - i + 1;
        i64 cnt = remain / days;
        cnt = min(i, cnt);
        ans.push_back(cnt);
        remain -= cnt * days;
    }
    debug(ans);
    for (auto i : ans) cout << i << ' ';
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