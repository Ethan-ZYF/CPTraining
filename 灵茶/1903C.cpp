#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), pref(n);
    for (auto& x : a)
        cin >> x;
    partial_sum(a.rbegin(), a.rend(), pref.rbegin());
    i64 ans = pref[0];
    for (int i = 1; i < n; i++)
        if (pref[i] > 0) ans += pref[i];
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