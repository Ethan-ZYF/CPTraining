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
    vector<i64> a(n);
    for (auto& x : a) cin >> x;
    vector<i64> pow = {0, 1};
    for (int i = 0; i < 40; i++) pow.push_back(pow.back() * 2);
    int ans = 0;
    i64 last = a[0];
    i64 added = 0;
    for (int i = 1; i < n; i++) {
        if(a[i] >= last) {
            last = a[i];
            continue;
        }
        while (a[i] + added < last) {
            ans++;
            added += pow[ans];
        }
        last = min(last, a[i] + added);
        // debug(ans, last);
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