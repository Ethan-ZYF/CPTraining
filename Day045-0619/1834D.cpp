#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> L(n), R(n), len(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        len[i] = R[i] - L[i];
    }

    int mn = *min_element(len.begin(), len.end());
    int mnr = *min_element(R.begin(), R.end());
    int mxl = *max_element(L.begin(), L.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // [### ]...
        // ....[   ]
        ans = max(ans, min(R[i], mxl) - L[i]);
        // ...[ ###]
        // [   ]....
        ans = max(ans, R[i] - max(L[i], mnr));
        // [## ##]..
        // ..[ ]....
        ans = max(ans, R[i] - L[i] - mn);
    }

    cout << 2 * ans << '\n';
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