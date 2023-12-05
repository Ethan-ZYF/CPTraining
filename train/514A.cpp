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
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - '0';
        t < 9 - t ? s[i] : s[i] = '0' + 9 - t;
    }
    if (s[0] == '0') {
        s[0] = '9';
    }
    cout << s << '\n';
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