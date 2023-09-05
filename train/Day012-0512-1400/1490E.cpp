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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<i64> pre(n);
    pre[0] = a[0].first;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    debug(n);
    debug(a);
    debug(pre);
    int last = -1;
    for (int i = 0; i < n - 1; i++) {
        if (pre[i] < a[i + 1].first) {
            last = i;
        }
    }
    debug(last);
    vector<int> ans;
    for (int i = last + 1; i < n; i++) {
        ans.push_back(a[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
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