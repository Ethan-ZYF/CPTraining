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
    debug(cnt);

    auto check = [&](int x) {
        i64 ex = 0;
        for (int c : cnt) {
            if (c > x) {
                ex += c - x;
            } else {
                ex -= (x - c) / 2;
            }
        }
        return ex <= 0;
    };

    int lo = 0, hi = m * 2 + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
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