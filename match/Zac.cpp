#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int cnt_tail0(i64 n) {
    int res = 0;
    while (n % 10 == 0) {
        res++;
        n /= 10;
    }
    return res;
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 ans = n, tail0 = 0;
    for (int i = 1; i <= k; i++) {
        i64 cur = n * i;
        int cur_tail0 = cnt_tail0(cur);
        debug(cur, cur_tail0);
        if (cur_tail0 > tail0) {
            tail0 = cur_tail0;
            ans = cur;
        } else if (cur_tail0 == tail0) {
            ans = max(ans, cur);
        }
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