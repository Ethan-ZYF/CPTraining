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
    s.push_back('X');
    int ans = 0;
    string t = "RGB";
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans++;
            for (auto x : t) {
                if (x != s[i + 1] and x != s[i - 1]) {
                    s[i] = x;
                    break;
                }
            }
        }
    }
    cout << ans << '\n' << s.substr(0, n) << '\n';
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