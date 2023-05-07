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
    int hf = n / 2;
    for (int i = 0; i < hf; i++) {
        b.push_back(abs(a[i] - a[n - i - 1]));
    }
    if (all_of(b.begin(), b.end(), [&](int x) { return x == 0; })) {
        cout << "0\n";
        return;
    }
    int res = reduce(b.begin(), b.end(), 0, [&](int x, int y) { return gcd(x, y); });
    cout << res << '\n';
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