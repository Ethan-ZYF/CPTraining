#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n;
    cin >> n;

    auto check = [&](i64 x) {
        i64 got = 0;
        i64 cur = n;
        while (cur) {
            i64 could = min(cur, x);
            got += could;
            cur -= could;
            cur -= cur / 10;
        }
        return got * 2 >= n;
    };

    i64 lo = 0, hi = n;
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
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}