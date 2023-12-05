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
    vector a(n, vector(m, 0));
    for (auto& row : a) {
        for (auto& x : row) {
            cin >> x;
        }
    }

    vector up(m, 0), minL(n, n);
    for (int i = 0; i < n; i++) {
        minL[i] = i;
        for (int j = 0; j < m; j++) {
            if (i and a[i][j] < a[i - 1][j]) {
                up[j] = i;
            }
            minL[i] = min(minL[i], up[j]);
        }
    }

    int k, L, R;
    cin >> k;
    while (k--) {
        cin >> L >> R;
        L--, R--;
        cout << (minL[R] <= L ? "Yes" : "No") << '\n';
    }
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