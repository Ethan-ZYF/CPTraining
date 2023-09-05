#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    i64 ans = 0, mask = 0;
    map<i64, int> cnt;
    cnt[0] = 1;
    for (auto c : s) {
        mask ^= 1 << c;
        ans += cnt[mask];
        cnt[mask]++;
    }
    cout << ans << '\n';
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