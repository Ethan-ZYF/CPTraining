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
        map<char, int> cnt;
        for (int j = 0; j < 100 and i + j < n; j++) {
            cnt[s[i + j]]++;
            int mxv = ranges::max(cnt | ranges::views::values);
            int sz = cnt.size();
            if (mxv <= sz) ans++;
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