#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    array<vector<int>, 26> pos{};
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        pos[x].push_back(i);
    }
    int m;
    cin >> m;
    while (m--) {
        string t;
        cin >> t;
        debug(t);
        vector<int> cnt(26);
        for (auto &c : t)
            ++cnt[c - 'a'];
        int ans = -1;
        // debug(cnt);
        for (int j = 0; j < 26; j++)
            if (cnt[j])
                ans = max(ans, pos[j][cnt[j] - 1]);
        cout << ans + 1 << "\n";
    }
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