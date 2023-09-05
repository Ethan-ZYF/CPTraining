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
    string s, t;
    cin >> s >> t;
    transform(s.begin(), s.end(), s.begin(), [](char c) {
        if (c == 'l') return '1';
        if (c == 'o') return '0';
        return c;
    });
    transform(t.begin(), t.end(), t.begin(), [](char c) {
        if (c == 'l') return '1';
        if (c == 'o') return '0';
        return c;
    });
    cout << (s == t ? "Yes" : "No") << '\n';
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