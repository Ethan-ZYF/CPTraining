#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ps(n + 1);
    for (auto& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), ps.begin() + 1, bit_xor());
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (ps[r] ^ ps[l - 1]) << '\n';
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