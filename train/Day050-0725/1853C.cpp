#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](i64 x) -> bool {
        i64 remain = x;
        for (int i = 0; i < k; i++) {
            int num = upper_bound(a.begin(), a.end(), remain) - a.begin();
            remain -= num;
        }
        return remain > 0;
    };

    i64 lo = 0, hi = 1e17 + 1;
    while (lo + 1 < hi) {
        i64 mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
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