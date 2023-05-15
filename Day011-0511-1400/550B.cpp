#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    auto check = [&](vector<int>& a) -> bool {
        int sum = accumulate(a.begin(), a.end(), 0LL);
        return sum >= l && sum <= r && a.back() - a.front() >= x;
    };
    i64 ans = 0;
    auto dfs = [&](auto&& self, int i, vector<int>& p) {
        if (i == n) {
            if (check(p))
                ans++;
            return;
        }
        p.push_back(a[i]);
        self(self, i + 1, p);
        p.pop_back();
        self(self, i + 1, p);
    };
    vector<int> p;
    dfs(dfs, 0, p);
    cout << ans << '\n';
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