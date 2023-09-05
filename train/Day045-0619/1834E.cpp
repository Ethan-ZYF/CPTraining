#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 INF = 1e10 + 1;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    set<i64> f, s;
    i64 ans = 1;
    for (auto& i : a) {
        set<i64> g;
        for (auto& j : f) {
            i64 m = lcm(i, j);
            if (m < INF) {
                s.insert(m);
                g.insert(m);
            }
        }
        g.insert(i);
        s.insert(i);
        f = g;
    }
    while (s.contains(ans)) ans++;
    cout << ans << '\n';
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