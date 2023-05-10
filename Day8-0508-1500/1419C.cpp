#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int cntx = ranges::count(a, x);
    if (cntx == n) {
        cout << 0 << '\n';
        return;
    }
    i64 acc = accumulate(a.begin(), a.end(), 0LL);
    if (acc == 1LL * n * x || cntx) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
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