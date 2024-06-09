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
    string s;
    cin >> n >> s;
    array<int, 26> cnt{};
    int mx = 0;
    for (char c : s) {
        cnt[c - 'a']++;
        mx = max(mx, cnt[c - 'a']);
    }
    if (mx * 2 <= n) {
        cout << (n & 1) << '\n';
    } else {
        cout << 2 * mx - n << '\n';
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