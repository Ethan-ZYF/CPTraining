#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
constexpr int MAXN = 4e5 + 5;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a)
        cin >> x;
    i64 ans = 1LL * n * (n + 1) / 2;
    array<i64, MAXN> cnt{};
    i64 cur = 0;
    cnt[0] = 1;
    for (auto ai : a) {
        cur ^= ai;
        for (i64 i = 0; i * i <= 2 * n; i++) {
            i64 x = i * i;
            if ((cur ^ x) < MAXN) ans -= cnt[cur ^ x];
        }
        cnt[cur]++;
    }
    cout << ans << '\n';
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