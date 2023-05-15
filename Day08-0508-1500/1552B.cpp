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
    vector<array<int, 5>> a(n);
    for (auto& x : a)
        for (auto& y : x) cin >> y;
    debug(a);

    int mx = 0;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
            if (a[i][j] < a[mx][j]) cnt++;
        if (cnt >= 3) mx = i;
    }
    for (int i = 0; i < n; i++) {
        if (i == mx) continue;
        int cnt = 0;
        for (int j = 0; j < 5; j++)
            if (a[i][j] < a[mx][j]) cnt++;
        if (cnt >= 3) mx = -2;
    }
    cout << mx + 1 << '\n';
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