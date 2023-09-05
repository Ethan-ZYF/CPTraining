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
    // ans = a[i0] + a[i1] + a[i2] - (r - l)
    // ans = a[i1] + (a[i0] + l) + (a[i2] - r)

    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) {
        a1[i] = a[i] + i;
        a2[i] = a[i] - i;
    }
    vector<int> lmax(n), rmax(n);
    lmax[0] = 0;
    rmax[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
        lmax[i] = a1[lmax[i - 1]] < a1[i] ? i : lmax[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        rmax[i] = a2[rmax[i + 1]] < a2[i] ? i : rmax[i + 1];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int l = lmax[i - 1];
        int r = rmax[i + 1];
        int sum = a[i] + a[l] + a[r] - (r - l);
        debug(l, i, r);
        debug(sum);
        ans = max(ans, sum);
    }
    cout << ans << endl;
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