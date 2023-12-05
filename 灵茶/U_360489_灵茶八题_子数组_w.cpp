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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1, bit_xor<int>());
    i64 ans = 0;
    for (int bit = 0; bit < 30; bit++) {
        int cnt = 0;
        for (auto x : pref) {
            cnt += (x >> bit) & 1;
        }
        ans += 1LL * cnt * (n + 1 - cnt) * (1 << bit);
    }
    cout << ans << "\n";
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