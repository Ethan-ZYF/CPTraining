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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        map<int, int> mp;
        int mx_cnt = 0;
        for (int j = i; j < n; j++) {
            mp[s[j]]++;
            mx_cnt = max(mx_cnt, mp[s[j]]);
            if (mx_cnt > 10)
                break;
            if (mx_cnt <= mp.size())
                ans++;
        }
    }
    cout << ans << '\n';
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