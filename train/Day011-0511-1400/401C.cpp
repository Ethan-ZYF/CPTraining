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
    if (n - m > 1) {
        cout << -1 << '\n';
        return;
    }
    if (m > n * 2 + 2) {
        cout << -1 << '\n';
        return;
    }
    if (m == n - 1) {
        for (int i = 0; i < m; i++) cout << "01";
        cout << '0';
    } else {
        while (n) {
            if (m > n) {
                cout << '1';
                m--;
            }
            cout << "10";
            m--, n--;
        }
        cout << string(m, '1');
    }
    cout << '\n';
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