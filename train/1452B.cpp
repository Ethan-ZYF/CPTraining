#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 dceil(i64 x, i64 y){
    return (x + y - 1) / y;
}

void solve() {
    int n, mx = 0;
    cin >> n;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    int mn = dceil(sum, n - 1);
    i64 need = 1LL * max(mx, mn) * (n - 1);
    cout << need - sum << "\n";
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