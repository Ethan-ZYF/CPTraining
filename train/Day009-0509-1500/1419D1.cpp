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
    int ans = (n + 1) / 2 - 1;
    int i = 0, j = ans;
    vector<int> res;
    while (i < ans) {
        res.push_back(a[j++]);
        res.push_back(a[i++]);
    }
    while(j < n) {
        res.push_back(a[j++]);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}