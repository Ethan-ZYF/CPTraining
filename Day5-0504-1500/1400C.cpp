#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.size();
    string w(n, '1');
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i - x >= 0) w[i - x] = '0';
            if (i + x < n) w[i + x] = '0';
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if ((i - x >= 0 and w[i - x] == '1') or (i + x < n and w[i + x] == '1'))
                continue;
            cout << -1 << '\n';
            return;
        }
    }
    cout << w << '\n';
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