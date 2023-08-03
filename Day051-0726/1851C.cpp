#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int cnt = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] == a[0]) cnt++;
        if (cnt == k) break;
    }
    if (cnt != k) {
        cout << "NO\n";
        return;
    }
    if (a[0] == a.back()) {
        cout << "YES\n";
        return;
    }
    cnt = count(a.begin() + i + 1, a.end(), a.back());
    if (cnt >= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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