#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> h(n);
    for (auto& x : h) {
        cin >> x;
        x %= a + b;
    }
    for (auto& x : h) {
        if (x == 0) {
            x = a + b;
        }
        x -= a;
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for (auto& x : h) {
        if (x <= 0) {
            ans++;
            continue;
        }
        int cnt = (x + a - 1) / a;
        if (k >= cnt) {
            k -= cnt;
            ans++;
        }
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