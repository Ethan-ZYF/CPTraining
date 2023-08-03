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
    vector<pair<int, int>> segs(m);
    for (auto& [l, r] : segs) {
        cin >> l >> r;
        l--;
    }
    int q;
    cin >> q;
    vector<int> qs(q);
    for (auto& x : qs) {
        cin >> x;
        x--;
    }
    auto check = [&](int x) -> bool {
        vector<int> a(n), ps(n + 1);
        for (int i = 0; i < x; i++) {
            a[qs[i]] = 1;
        }
        partial_sum(a.begin(), a.end(), ps.begin() + 1);
        for (auto& [l, r] : segs) {
            if (2 * (ps[r] - ps[l]) > r - l) return true;
        }
        return false;
    };
    int l = 0, r = q + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == q + 1) {
        cout << "-1\n";
    } else {
        cout << r << '\n';
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