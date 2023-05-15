#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // vector<vector<int>> cnt(n + 1, vector<int>(26));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cnt[i + 1][j] = cnt[i][j] + (s[i] == 'a' + j);
    //     }
    // }
    // debug(cnt);
    // auto check = [&](int x) -> bool {
    //     debug(x);
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < 26; j++) {
    //             if (i + x > n) break;
    //             debug(cnt[i + x][j] - cnt[i][j], x - k);
    //             if (cnt[i + x][j] - cnt[i][j] >= x - k) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // };
    // int l = 0, r = n + 1;
    // while (l + 1 < r) {
    //     int mid = (l + r) / 2;
    //     if (check(mid)) {
    //         l = mid;
    //     } else {
    //         r = mid;
    //     }
    // }
    // cout << l << '\n';
    array<int, 26> cnt{};
    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        cnt[s[r] - 'a']++;
        while (*max_element(cnt.begin(), cnt.end()) + k < r - l + 1) {
            cnt[s[l++] - 'a']--;
        }
        debug(l, r, cnt);
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
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