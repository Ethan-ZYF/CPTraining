#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    if (n % x != 0) {
        cout << "-1\n";
        return;
    }
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    a[1] = x, a[n] = 1;
    while (x < n) {
        for (int i = 2 * x; i <= n; i += x) {
            if (n % i == 0) {
                a[x] = i;
                x = i;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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