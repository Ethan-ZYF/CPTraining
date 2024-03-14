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
    char last = s[0];
    int cnt = 1, cntw = 0;
    for (char c : s.substr(1)) {
        if (c == last) {
            cnt++;
        } else {
            if (last == 'v') {
                cntw += cnt - 1;
            }
            last = c;
            cnt = 1;
        }
    }
    if (last == 'v')
        cntw += cnt - 1;
    cnt = 0;
    int left = 0, right = cntw;
    i64 ans = 0;
    for (char c : s) {
        if (c == 'o') {
            left += max(cnt - 1, 0);
            right -= max(cnt - 1, 0);
            ans += 1LL * left * right;
            cnt = 0;
        } else if (c == 'v') {
            cnt++;
        }
    }
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