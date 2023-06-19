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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int g = reduce(a.begin(), a.end(), 0, gcd<int, int>);
    if (g != 1) {
        cout << -1 << '\n';
        return;
    }
    int cnt = count(a.begin(), a.end(), 1);
    if (cnt) {
        cout << n - cnt << '\n';
        return;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = i - 1; j >= 0; j--) {
            x = gcd(x, a[j]);
            if (x == 1) {
                ans = min(ans, i - j);
                break;
            }
        }
    }
    cout << ans + n - 1 << '\n';
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