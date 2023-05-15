#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> cnt(60);
    for (int j = n; j--;) {
        i64 x;
        cin >> x;
        int i = 0;
        while (x) {
            cnt[i] += x % k;
            x /= k;
            i++;
        }
    }
    auto flag = all_of(cnt.begin(), cnt.end(), [](auto x) { return x <= 1; });
    cout << (flag ? "YES" : "NO") << '\n';
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