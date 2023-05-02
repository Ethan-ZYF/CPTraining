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
    vector<int> a(n), w(k);
    for (auto& x : a) cin >> x;
    for (auto& wi : w) cin >> wi;
    sort(a.begin(), a.end());
    sort(w.rbegin(), w.rend());
    vector<multiset<int>> s(k);
    int l = 0, r = n - 1;
    for (int i = 0; i < k; i++) {
        if (w[i] == 1) {
            s[i].insert(a[r--]);
        }
    }
    for (int i = 0; i < k; i++) {
        if (w[i] == 1) {
            continue;
        }
        s[i].insert(a[l++]); 
        s[i].insert(a[r--]);
        for(int j = 2; j < w[i]; j++) {
            s[i].insert(a[l++]);
        }
    }
    debug(s);
    i64 ans = 0;
    for (auto& si : s) {
        ans += *si.begin() + *si.rbegin();
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