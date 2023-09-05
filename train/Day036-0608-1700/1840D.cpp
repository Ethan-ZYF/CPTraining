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
    sort(a.begin(), a.end());
    auto check = [&](int x) -> bool {
        int cur = 1;
        int last = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > last + 2 * x) {
                cur++;
                last = a[i];
                debug(i, a[i], last);
            }
        }
        debug(x, cur);
        return cur <= 3;
    };
    int lo = -1, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << endl;
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