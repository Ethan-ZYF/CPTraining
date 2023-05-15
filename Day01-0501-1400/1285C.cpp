#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

vector<pair<i64, int>> factor(i64 x) {
    vector<pair<i64, int>> res;
    for (i64 i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            res.emplace_back(i, cnt);
        }
    }
    if (x > 1) {
        res.emplace_back(x, 1);
    }
    return res;
}

void solve() {
    i64 x;
    cin >> x;
    auto f = factor(x);
    i64 a = x, b = x;
    i64 mn = x;
    auto dfs = [&](auto self, int i, i64 u, i64 v) -> void {
        if (i == f.size()) {
            if(max(u, v) < mn) {
                mn = max(u, v);
                a = u;
                b = v;
            }
            return;
        }
        i64 p = f[i].first;
        int cnt = f[i].second;
        i64 pw = pow(p, cnt);
        self(self, i + 1, u * pw, v);
        self(self, i + 1, u, v * pw);
    };
    dfs(dfs, 0, 1, 1);
    cout << a << " " << b << "\n";
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