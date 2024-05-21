#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 C2(i64 n) {
    return n * (n - 1) / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        int j = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        ans += C2(j - i - 1);
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