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
    for (auto& x : a)
        cin >> x;

    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    if (n == 1) {
        cout << "1\n";
        return;
    }
    debug(a);
    int ans = 2;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] and a[i] > a[i + 1]) ans++;
        if (a[i] < a[i - 1] and a[i] < a[i + 1]) ans++;
    }
    cout << ans << '\n';
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