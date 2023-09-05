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
    char c = '*';
    string ans;

    for (int i = 0; i < n; i++) {
        if (c == '*') {
            c = s[i];
            ans += s[i];
        } else {
            if (s[i] != c) {
                continue;
            }
            c = '*';
        }
    }
    cout << ans << endl;
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