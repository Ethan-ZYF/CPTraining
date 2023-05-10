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
    vector<int> a;
    int nums1 = 0, nums2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1)
            nums1++;
        else if (x == -2)
            nums2++;
        else
            a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int sz = a.size();
    int ans = 0;
    int gap = m - sz;
    int res = min(gap, nums1) + sz;
    ans = max(ans, res);
    res = min(gap, nums2) + sz;
    ans = max(ans, res);
    auto f = [&](int i) {
        int l = a[i] - 1 - i;
        int r = m - a[i] - (sz - i - 1);
        res = min(l, nums1) + min(r, nums2) + sz;
        ans = max(ans, res);
    };
    for (int i = 0; i < sz; i++) {
        f(i);
    }
    cout << ans << '\n';
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