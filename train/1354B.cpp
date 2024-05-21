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
    int n = s.size();

    int l = 0, ans = n * 2;
    array<int, 3> bs{};
    for (int r = 0; r < n; r++) {
        while (l < r && bs[0] && bs[1] && bs[2]) {
            debug(l, r, bs);
            ans = min(ans, r - l);
            bs[s[l] - '1']--;
            l++;
        }
        bs[s[r] - '1']++;
    }
    while (l < n && bs[0] && bs[1] && bs[2]) {
        debug(l, bs);
        ans = min(ans, n - l);
        bs[s[l] - '1']--;
        l++;
    }
    cout << (ans == n * 2 ? 0 : ans) << '\n';
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