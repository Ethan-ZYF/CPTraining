#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int MX = 2e5 + 5;

void solve() {
    i64 h, n;
    cin >> h >> n;
    vector<i64> a(n), c(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : c)
        cin >> x;
    auto check = [&](i64 x) -> bool {
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (x + c[i] - 1) / c[i] * a[i];
        }
        return ans >= h;
    };
    i64 lo = 0, hi = 4e10 + 1;
    while (lo + 1 < hi) {
        i64 mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << '\n';
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