#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
constexpr i64 inf = 1e18;

i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    i64 ans = inf;
    for (int c = 1; power(c, n - 1, inf) <= 1e10; c++) {
        i64 cur = 0;
        i64 p = 1;
        for (int i = 0; i < n; i++) {
            cur += abs(a[i] - p);
            p *= c;
        }
        ans = min(ans, cur);
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