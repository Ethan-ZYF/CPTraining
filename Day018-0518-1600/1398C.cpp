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
    vector<int> a(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    debug(a);
    partial_sum(a.begin(), a.end(), pre.begin() + 1);
    debug(pre);
    map<int, int> cnt;
    cnt[0] = 1;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[pre[i] - i];
        cnt[pre[i] - i]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}