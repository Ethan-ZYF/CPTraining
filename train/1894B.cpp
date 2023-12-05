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
    map<int, vector<int>> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]].push_back(i);
    }
    int tot = 0;
    for (auto& [k, v] : cnt) {
        if (v.size() >= 2) tot++;
    }
    if (tot < 2) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n);
    for (auto& [k, v] : cnt) {
        if (v.size() >= 2) {
            ans[v[0]] = 1;
            int cur = 2;
            if (tot == 1) cur = 3;
            for (int i = 1; i < v.size(); i++) {
                ans[v[i]] = cur;
            }
            tot--;
        } else {
            ans[v[0]] = 1;
        }
    }
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
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