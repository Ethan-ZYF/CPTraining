#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    i64 oddsum = 0, evensum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evensum += a[i];
        } else {
            oddsum += a[i];
        }
    }
    int start = 0;
    if (oddsum < evensum) {
        start = 1;
    }
    for (int i = start; i < n; i += 2) {
        a[i] = 1;
    }
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}