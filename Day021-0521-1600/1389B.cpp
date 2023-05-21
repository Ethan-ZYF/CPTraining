#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    vector<i64> s(n + 1);
    partial_sum(a.begin(), a.end(), s.begin() + 1);
    i64 ans = s[k + 1];
    for (int j = 0; j <= z; j++) {
        int right = k + 1 - 2 * j;
        if (right < 0) continue;
        i64 cur = s[right];
        i64 mx = 0;
        for (int i = 0; i < right; i++) {
            mx = max(mx, a[i] + a[i + 1]);
        }
        cur += 1LL * mx * j;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}