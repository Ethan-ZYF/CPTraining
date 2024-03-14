#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, i64> X, Y;
    map<pair<int, int>, i64> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += X[x] + Y[y] - cnt[{x, y}];
        X[x]++, Y[y]++;
        cnt[{x, y}]++;
    }

    cout << ans << '\n';

    return 0;
}