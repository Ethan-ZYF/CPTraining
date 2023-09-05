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
    vector<int> a(n), b(n), L(n), R(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (b[j] < a[i]) {
            j++;
        }
        L[i] = j;
    }
    j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        while (j + 1 < n && a[j + 1] <= b[j]) {
            j++;
        }
        R[i] = j;
    }

    debug(L, R);
    for (int i = 0; i < n; i++) {
        cout << b[L[i]] - a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << b[R[i]] - a[i] << " \n"[i == n - 1];
    }
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