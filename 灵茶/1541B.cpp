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
    vector<i64> a(n + 1);
    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<pair<int, int>> tmp;
    for (int x = 1; x <= 2 * n; x++) {
        for (int i = 1; i * i <= 2 * n; i++) {
            if (x % i)
                continue;
            int j = x / i;
            if (i < j) {
                tmp.push_back({i, j});
            }
        }
    }
    debug(tmp);
    i64 ans = 0;
    for (auto [i, j] : tmp) {
        if (pos.count(i) and pos.count(j)) {
            if (pos[i] + pos[j] == i * j)
                ans++;
        }
    }
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