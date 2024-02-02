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
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> r >> l;
        int lo, hi;
        lo = max(0, i - l);
        hi = min(n - 1, i + r);
        debug(lo, hi);
        ps[lo]++;
        ps[hi + 1]--;
    }
    debug(ps);
    partial_sum(ps.begin(), ps.end(), ps.begin());
    debug(ps);
    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ps[i] >= x) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt >= x) {
                return true;
            }
        }
        return false;
    };
    int lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';
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