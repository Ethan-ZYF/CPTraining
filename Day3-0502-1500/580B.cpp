#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (auto& [s, m] : a) {
        cin >> s >> m;
    }
    sort(a.begin(), a.end());
    debug(a);
    i64 window = 0, ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++){
        while (j < n && a[j].first - a[i].first < d) {
            window += a[j].second;
            j++;
        }
        ans = max(ans, window);
        window -= a[i].second;
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