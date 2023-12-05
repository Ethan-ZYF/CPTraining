#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }

    auto check = [&](i64 x) -> bool {
        i64 pos = 0, neg = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] - x > 0) {
                pos += cnt[i] - x;
            } else {
                neg += (x - cnt[i]) / 2;
            }
        }
        debug(x, pos, neg);
        return pos <= neg;
    };

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << '\n';
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