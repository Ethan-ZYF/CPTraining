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
    map<int, vector<i64>> X;
    map<int, vector<i64>> Y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            X[x].push_back(i);
            Y[x].push_back(j);
        }
    }
    i64 ans = 0;
    for (auto& [k, v] : X) {
        sort(v.begin(), v.end());
        i64 sum = 0;
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            ans += v[i] * i - sum;
            sum += v[i];
        }
    }
    for (auto& [k, v] : Y) {
        sort(v.begin(), v.end());
        i64 sum = 0;
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            ans += v[i] * i - sum;
            sum += v[i];
        }
    }
    cout << ans << '\n';
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