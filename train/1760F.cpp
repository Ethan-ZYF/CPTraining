#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, c, d;
    cin >> n >> c >> d;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    auto check = [&](i64 x) -> bool {
        i64 tot = 0;
        i64 q = d / (x + 1), r = d % (x + 1);
        i64 last1 = min(x + 1, n), last2 = min(r, n);
        i64 tot0 = accumulate(a.begin(), a.begin() + last1, 0LL);
        tot0 *= q;
        i64 tot1 = accumulate(a.begin(), a.begin() + last2, 0LL);
        tot1 += tot0;
        debug(x, q, r, tot0, tot1);
        return tot1 >= c;
    };

    i64 lo = -1, hi = 1e9 + 1;
    while (hi - lo > 1) {
        i64 mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    if (lo == -1) {
        cout << "Impossible\n";
    } else if (hi >= 1e9) {
        cout << "Infinity\n";
    } else {
        cout << lo << '\n';
    }
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