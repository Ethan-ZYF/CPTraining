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
    vector<vector<int>> pos(26, {-1});
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    int ans = n;
    for (auto& ps : pos) {
        ps.push_back(n);
        int cur = 0;
        for (int i = 0; i < ps.size() - 1; i++) {
            cur = max(cur, ps[i + 1] - ps[i]);
        }
        debug(ps);
        ans = min(ans, cur);
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