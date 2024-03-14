#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 MOD = 1e9 + 7;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    copy_n(istream_iterator<i64>(cin), n, a.begin());
    i64 cur = 1, i = -2;
    i64 and_ = accumulate(a.begin(), a.end(), -1, [&](i64 x, i64 y) {
        if (0 < i++)
            cur = cur * i % MOD;
        return x & y;
    });
    i64 cnt = count(a.begin(), a.end(), and_);
    i64 ans = cnt * (cnt - 1) % MOD * cur % MOD;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}