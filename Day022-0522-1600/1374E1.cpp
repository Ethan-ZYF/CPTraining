#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> t1, t2, t3;
    vector<i64> s1, s2, s3;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a && b) {
            t3.push_back(t);
        } else if (a) {
            t1.push_back(t);
        } else if (b) {
            t2.push_back(t);
        }
    }
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    sort(t3.begin(), t3.end());
    i64 ans = 1e18;
    auto f = [&](const auto &a, auto &b) {
        b.resize(a.size() + 1);
        for (int i = 0; i < int(a.size()); ++i)
            b[i + 1] = b[i] + a[i];
    };
    f(t1, s1);
    f(t2, s2);
    f(t3, s3);
    for (int i = 0; i <= k; ++i) {
        if (int(t3.size()) >= i && int(t1.size()) >= k - i && int(t2.size()) >= k - i) {
            i64 res = s3[i] + s2[k - i] + s1[k - i];
            ans = min(ans, res);
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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