#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, s;
    cin >> n >> s;
    if (s - n >= n) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << ' ';
        }
        cout << s - n + 1 << '\n';
        cout << n << endl;
    } else {
        cout << "NO\n";
    }
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