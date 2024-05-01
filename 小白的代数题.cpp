#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

i64 dceil(i64 a, i64 b) {
    return ceil((double)a / b);
}

bool solve_odd(i64 n, i64 a, i64 b, i64 L, i64 R) {
    i64 A = 2 * a + 3, B = 2 * b, N = 2 * n + 3;
    i64 x, y;
    i64 g = exgcd(A, B, x, y);
    if (N % g != 0)
        return false;
    i64 x0 = x * N / g, y0 = y * N / g;
    i64 dx = B / g, dy = A / g;
    i64 s = dceil(L - x0, dx);
    x0 += s * dx, y0 -= s * dy;
    debug(x0, y0, s, dx);
    return y0 >= 0 and x0 % 2 == 1 and x0 <= R;
}

bool solve_even(i64 n, i64 a, i64 b, i64 L, i64 R) {
    i64 A = 2 * a + 3, B = 2 * b, N = 2 * n;
    i64 x, y;
    i64 g = exgcd(A, B, x, y);
    if (N % g != 0)
        return false;
    i64 x0 = x * N / g, y0 = y * N / g;
    debug(x0, y0, A, B);
    i64 dx = B / g, dy = A / g;
    i64 s = dceil(L - x0, dx);
    x0 += s * dx, y0 -= s * dy;
    debug(x0, y0, s);
    return y0 >= 0 and x0 % 2 == 0 and x0 <= R;
}

void solve() {
    i64 n, a, b, L, R;
    cin >> n >> a >> b >> L >> R;
    if (solve_odd(n, a, b, L, R)) {
        debug("odd");
        cout << "YES\n";
        return;
    }
    if (solve_even(n, a, b, L, R)) {
        debug("even");
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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