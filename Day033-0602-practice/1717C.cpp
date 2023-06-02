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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << "NO\n";
            return;
        }
    }
    a.push_back(a[0]);
    b.push_back(b[0]);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (b[i] <= b[i + 1] + 1) continue;
        // a[i] 可以等  a[i + 1] 变成 b[i + 1] 再变，变的上限是b[i + 1] + 1
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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