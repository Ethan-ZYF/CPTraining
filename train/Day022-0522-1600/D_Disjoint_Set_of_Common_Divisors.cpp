#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
vector<pair<i64, int>> factor(i64 n) {
    vector<pair<i64, int>> res;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i, 0);
            while (n % i == 0) {
                res.back().second++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

void solve() {
    i64 x, y;
    cin >> x >> y;
    i64 g = gcd(x, y);
    auto f = factor(g);
    cout << f.size() + 1 << endl;
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