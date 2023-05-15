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
    vector<int> a(n), b;
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n / 2; i++)
        b.push_back(abs(a[i] - a[n - i - 1]));
    cout << reduce(b.begin(), b.end(), 0, gcd<int, int>) << '\n';
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