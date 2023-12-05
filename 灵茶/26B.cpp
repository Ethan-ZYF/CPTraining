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
    int ans = 0;
    int b = 0;
    for (auto c : s) {
        if (c == '(') {
            b++;
            ans++;
        } else {
            if (b > 0) {
                b--;
                ans++;
            }
        }
    }
    ans -= b;
    cout << ans << endl;
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