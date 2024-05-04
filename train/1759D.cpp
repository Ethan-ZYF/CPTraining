#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

pair<int, int> get(int n) {
    int cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0) {
        n /= 2;
        cnt2++;
    }
    while (n % 5 == 0) {
        n /= 5;
        cnt5++;
    }
    return {cnt2, cnt5};
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    auto [cur2, cur5] = get(n);
    for (int zeros = 18; zeros >= 0; zeros--) {
        int need2 = zeros - cur2, need5 = zeros - cur5;
        need2 = max(0, need2);
        need5 = max(0, need5);
        i64 cur = powl(2, need2) * powl(5, need5);
        if (cur <= k) {
            i64 d = k / cur;
            cout << d * cur * n << '\n';
            return;
        }
    }
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