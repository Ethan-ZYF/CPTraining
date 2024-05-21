#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    int sum = d12 + d23 + d31;
    if (sum % 2 == 1 or sum / 2 + 1 > n or d12 + d23 < d31 or d12 + d31 < d23 or d23 + d31 < d12) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int x1 = (d12 + d31 - d23) / 2;
    int x2 = (d12 + d23 - d31) / 2;
    int x3 = (d23 + d31 - d12) / 2;
    int cnt = 3, root;
    if (x1 == 0) {
        root = 1;
    } else if (x2 == 0) {
        root = 2;
    } else if (x3 == 0) {
        root = 3;
    } else {
        root = ++cnt;
    }
    debug(root);
    if (x1) {
        int cur = root;
        for (int i = 1; i < x1; i++) {
            cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        cout << cur << " " << 1 << "\n";
    }
    if (x2) {
        int cur = root;
        for (int i = 1; i < x2; i++) {
            cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        cout << cur << " " << 2 << "\n";
    }
    if (x3) {
        int cur = root;
        for (int i = 1; i < x3; i++) {
            cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        cout << cur << " " << 3 << "\n";
    }
    if (cnt < n) {
        for (int i = cnt + 1; i <= n; i++) {
            cout << root << " " << i << "\n";
        }
    }
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