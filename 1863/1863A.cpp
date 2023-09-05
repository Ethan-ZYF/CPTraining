#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    bool yes = a >= n;
    int sum = a;
    for (auto c : s) {
        a += c == '+' ? 1 : -1;
        sum += c == '+' ? 1 : 0;
        yes |= a >= n;
    }
    if (yes) {
        cout << "YES\n";
    } else if (sum < n) {
        cout << "NO\n";
    } else {
        cout << "MAYBE\n";
    }
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