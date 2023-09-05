#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 f1[51], f2[51];
void init() {
    f1[0] = 1, f1[1] = 0;
    f2[0] = 0, f2[1] = 1;
    for (int i = 2; i <= 50; i++) {
        f1[i] = f1[i - 1] + f1[i - 2];
        f2[i] = f2[i - 1] + f2[i - 2];
    }
}

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k > 50) {
        cout << 0 << endl;
        return;
    }
    i64 a = f1[k - 1], b = f2[k - 1];
    debug(a, b);
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        i64 x = 1LL * a * i;
        if (x > n) break;
        if ((n - x) % b == 0) {
            i64 y = (n - x) / b;
            if (y < i) continue;
            debug(n - x);
            debug(x, y);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}