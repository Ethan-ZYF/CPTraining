#include <bits/stdc++.h>
using namespace std;
namespace rgs = std::ranges;
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<array<int, 3>> queries;
    for (int i = 0; i < m; i++) {
        int x, v;
        cin >> x >> v;
        x--;
        queries.push_back({x, i, v});
    }
    rgs::sort(queries);

    auto [len1, lis1] = LIS(a);
    reverse(a.begin(), a.end());
    for (auto& x : a)
        x = -x;
    auto [len2, lis2] = LIS(a);
    reverse(lis2.begin(), lis2.end());
    debug(lis1);
    debug(lis2);

    int maxLen = 0;
    

    std::vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int idx = queries[i][0], j = queries[i][1];
        if (res[idx] == 3)
            ans[j] = std::max(maxLen - 1, p[j] + s[j] - 1);
        else
            ans[j] = std::max(maxLen, p[j] + s[j] - 1);
    }

    for (int i = 0; i < m; i++) {
        std::cout << ans[i] << "\n";
    }
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