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
    string s;
    cin >> s;
    int b = 0;
    for (auto c : s) {
        if (c == '(') {
            b++;
        } else {
            b--;
        }
    }
    if (b != 0) {
        cout << -1 << endl;
        return;
    }
    i64 ans = 0;
    b = 0;
    for (auto c : s) {
        debug(b, c, ans);
        if (b < 0 and c == '(') {
            ans += -b;
        }
        if (c == '(') {
            b++;
        } else {
            b--;
        }
    }
    cout << ans << endl;
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