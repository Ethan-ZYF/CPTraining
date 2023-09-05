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
    map<int, int> cnt;
    for (auto x : a) cnt[x]++;
    bool flag = n % 2 == 1;
    int res = flag ? 1 : 0;
    int mxcnt = 0;
    for (auto [x, c] : cnt) {
        mxcnt = max(mxcnt, c);
    }
    if (flag) mxcnt--, n--;
    int rest = n - mxcnt;
    res += max(0, mxcnt - rest);
    cout << res << '\n';
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