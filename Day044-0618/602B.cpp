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
    multiset<int> s;
    
    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        s.insert(a[r]);
        while (*s.rbegin() - *s.begin() > 1) {
            s.extract(a[l++]);
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';

    // int r = 0, ans = 0;
    // for (int l = 0; l < n; l++) {
    //     do {
    //         ans = max(ans, r - l);
    //         s.insert(a[r++]);
    //     } while (r <= n and *s.rbegin() - *s.begin() <= 1);
    //     s.extract(a[l]);
    // }
    // cout << ans << '\n';
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