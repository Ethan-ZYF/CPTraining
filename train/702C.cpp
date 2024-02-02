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
    vector<i64> a(n), b(m);
    for (auto& it : a)
        cin >> it;
    for (auto& it : b)
        cin >> it;
    b.insert(b.begin(), -1e18);
    b.push_back(1e18);
    i64 j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (b[j + 1] <= a[i])
            j++;
        ans = max(ans, min(a[i] - b[j], b[j + 1] - a[i]));
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