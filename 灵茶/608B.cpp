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
    array<int, 2> cnt{};
    for (int i = 0; i <= m - n; i++)
        cnt[t[i] - '0']++;
    i64 ans = cnt[1 ^ (s[0] - '0')];
    for (int i = 1, j = m - n + 1; i < n; i++, j++) {
        cnt[t[i - 1] - '0']--;
        cnt[t[j] - '0']++;
        ans += cnt[1 ^ (s[i] - '0')];
    }
    cout << ans << '\n';
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