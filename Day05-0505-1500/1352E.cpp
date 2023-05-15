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
    vector<i64> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    partial_sum(a.begin(), a.end(), pref.begin() + 1);
    int ans = 0;
    for (auto x : a) {
        int l = 0;
        for (int r = 0; r < n; r++){
            while(pref[r + 1] - pref[l] > x) {
                l++;
            }
            if (r - l >= 1 && pref[r + 1] - pref[l] == x) {
                ans++;
                break;
            }
        }
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