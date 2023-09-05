#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    vector<int> a = {3, 1, 4, 1, 5, 9};
    int n = a.size();
    vector<int> p(n + 1);
    partial_sum(a.begin(), a.end(), p.begin() + 1);
    debug(p);
    char l, r;
    cin >> l >> r;
    int L = l - 'A', R = r - 'A';
    if (L > R) swap(L, R);
    debug(L, R);
    cout << p[R] - p[L] << '\n';
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