#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    char mx = 'z' + 1;
    string res(n, mx);
    for (int i = 0; i < n; i++) {
        if (i + m - 1 >= n) break;
        string tmp = s;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (tmp[i + j] == '?') {
                tmp[i + j] = t[j];
            } else if (tmp[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int j = 0; j < n; j++) {
                if (tmp[j] == '?') tmp[j] = 'a';
            }
            if (tmp < res) res = tmp;
        }
    }
    if (res == string(n, mx)) {
        cout << "UNRESTORABLE\n";
    } else {
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}