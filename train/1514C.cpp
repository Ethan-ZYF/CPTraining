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
    i64 p = 1;
    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            p = p * i % n;
            res.push_back(i);
        }
    }
    debug(p);
    if (p != 1) {
        cout << res.size() - 1 << '\n';
        for (auto x : res) {
            if (x != p) cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << res.size() << '\n';
        for (auto x : res)
            cout << x << ' ';
        cout << '\n';
    }
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