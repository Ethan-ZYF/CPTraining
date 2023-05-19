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
    vector<string> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    debug(a);
    debug(b);
    auto f = [&](int i, int j) -> bool {
        for (int x = 0; x < m; x++)
            for (int y = 0; y < m; y++)
                if (a[i + x][j + y] != b[x][y])
                    return false;
        return true;
    };
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {
            if (f(i, j)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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