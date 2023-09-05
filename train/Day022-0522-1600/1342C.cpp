#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 a, b, q;
    cin >> a >> b >> q;
    i64 c = lcm(a, b);
    vector<i64> cnt(c + 1);
    for (int i = 1; i <= c; i++) {
        cnt[i] = cnt[i - 1];
        if (i % a % b != i % b % a) {
            cnt[i]++;
        }
    }
    debug(cnt);
    auto f = [&](i64 x) -> i64 {
        i64 res = x / c * cnt[c] + cnt[x % c];
        return res;
    };
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        l--;
        cout << f(r) - f(l) << ' ';
    }
    cout << '\n';
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