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
    vector<int> a(n);
    for (auto& it : a) cin >> it;
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        if (idx.count(x - a[i])) {
            cout << idx[x - a[i]] + 1 << ' ' << i + 1 << '\n';
            return;
        }
        idx[a[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}