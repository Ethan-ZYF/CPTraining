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
    vector<int> a(n), h(n), s(n + 1);
    for (auto& x : a) cin >> x;
    for (auto& x : h) cin >> x;
    partial_sum(a.begin(), a.end(), s.begin() + 1);
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i and h[i - 1] % h[i] != 0) j = i;
        while (j <= i and s[i + 1] - s[j] > k) j++;
        ans = max(ans, i - j + 1);
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