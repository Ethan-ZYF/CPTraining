#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, t;
    cin >> n >> t;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        mp[x] = vector<int>(c);
        for (int j = 0; j < c; j++) {
            cin >> mp[x][j];
        }
    }
    debug(mp);
    map<int, int> cnt;
    int ans = 0;
    for (auto& [x, v] : mp) {
        for (auto y : v) {
            cnt[y]++;
        }
        int remain = t - x;
        int cur = 0;
        for (auto [y, c] : cnt) {
            while (c > 0 && remain >= y) {
                remain -= y;
                c--;
                cur++;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
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