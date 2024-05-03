#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
constexpr i64 INF = 1e13;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        char c1 = a[i], c2 = b[i];
        if (c1 != c2)
            tmp.push_back(i);
    }
    debug(tmp);
    if (tmp.size() % 2) {
        cout << -1 << '\n';
        return;
    }
    if (tmp.empty()) {
        cout << 0 << '\n';
        return;
    }
    int m = tmp.size();
    y = min(y, x);
    x = min(x, y + y);
    if (m > 3) {
        cout << 1LL * y * m / 2 << '\n';
    } else {
        if (tmp[0] + 1 == tmp[1]) {
            cout << x << '\n';
        } else {
            cout << y << '\n';
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