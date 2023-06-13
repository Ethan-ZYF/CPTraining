#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

bool cmp(pair<int, int>& x, pair<int, int>& y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end(), cmp);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i].first].push_back(a[i].second);
    }
    debug(mp);
    i64 ans = 0;
    for (auto& [x, y] : mp) {
        int m = y.size();
        for (int i = 0; i < min(m, x); i++) {
            ans += y[i];
        }
    }
    cout << ans << endl;
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