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
    vector<int> a(n), c1(n), c2(n);
    for (auto& x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) c1[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[i + 1]) c2[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        c1[i + 1] += c1[i];
    }
    for (int i = n - 1; i > 0; i--) {
        c2[i - 1] += c2[i];
    }
    debug(c1);
    debug(c2);
    int ans = c2[0];
    ans = min(ans, c1.back() + 1);
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, c1[i] + c2[i + 1] + 1);
    }
    cout << ans << "\n";
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