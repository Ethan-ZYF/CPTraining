#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr double pi = numbers::pi;

void solve() {
    int n;
    cin >> n;
    double alpha = pi / n;
    double beta = alpha;
    double ans = 1;
    for (int i = 0; i < n / 2; i++) {
        ans += cos(beta) * 2;
        beta += alpha;
    }
    cout << fixed << setprecision(9) << ans << '\n';
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