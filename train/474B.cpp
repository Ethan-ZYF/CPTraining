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
    vector<i64> a(n), s(n + 1);
    for (auto& x : a) {
        cin >> x;
    }
    partial_sum(a.begin(), a.end(), s.begin() + 1);
    int q;
    cin >> q;
    while (q--) {
        i64 m;
        cin >> m;
        int i = lower_bound(s.begin(), s.end(), m) - s.begin();
        cout << i << '\n';
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