#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> a(n);
    for (auto& [l, r] : a) {
        cin >> l >> r;
    }
    vector<int> cnt(200005);
    for (int i = 0; i < n; i++) {
        cnt[a[i].first]++;
        cnt[a[i].second + 1]--;
    }
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    vector<int> ans(200005);
    for (int i = 0; i < 200005; i++) {
        ans[i] = cnt[i] >= k;
    }
    partial_sum(ans.begin(), ans.end(), ans.begin());
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[r] - ans[l - 1] << '\n';
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