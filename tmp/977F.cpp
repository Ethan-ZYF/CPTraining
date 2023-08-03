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

    map<int, int> dp;
    for (auto x : a) dp[x] = dp[x - 1] + 1;
    int mx = 0, key = 0;
    for (auto [k, v] : dp) {
        if (v > mx) {
            mx = v;
            key = k;
        }
    }
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == key) {
            ans.push_back(i + 1);
            key--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
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