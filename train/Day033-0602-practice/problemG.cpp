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
    i64 ans = 0;
    vector<int> a(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] / k;
        a[i] %= k;
        s.insert(a[i]);
    }

    while (!s.empty()) {
        int x = *s.begin();
        s.erase(s.begin());

        auto it = s.lower_bound(k - x);
        if (it != s.end()) {
            s.erase(it);
            ans++;
        }
    }
    cout << ans << endl;
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