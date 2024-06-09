#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

pair<int, vector<int>> LIS(const vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1e9);
    int len = 0;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        len = max(len, pos + 1);
        lis.push_back(pos + 1);
    }
    return {len, lis};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    auto [len1, lis1] = LIS(a);
    reverse(a.begin(), a.end());
    for (auto& x : a)
        x = -x;
    auto [len2, lis2] = LIS(a);
    reverse(lis2.begin(), lis2.end());
    debug(lis1);
    debug(lis2);
    vector<int> ans(n, 2);
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        if (lis1[i] + lis2[i] - 1 == len1) {
            pre[lis1[i]]++;
        } else {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (lis1[i] + lis2[i] - 1 == len1) {
            ans[i] = pre[lis1[i]] == 1 ? 3 : 2;
        }
    }
    for (auto x : ans) {
        cout << x;
    }
    cout << '\n';
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