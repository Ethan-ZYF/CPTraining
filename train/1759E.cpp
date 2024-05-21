#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto dfs = [&](auto&& self, int i, i64 cur, int blue, int green) -> int {
        if (i == n) return 0;
        if (cur > a[i]) return 1 + self(self, i + 1, cur + a[i] / 2, blue, green);
        int ans1 = blue ? self(self, i, cur * 3, blue - 1, green) : 0;
        int ans2 = green ? self(self, i, cur * 2, blue, green - 1) : 0;
        return max(ans1, ans2);
    };

    int ans = dfs(dfs, 0, h, 1, 2);
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