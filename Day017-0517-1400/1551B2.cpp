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

    vector<int> a(n), cnt(n);
    vector<int> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        if (cnt[a[i]] <= k) {
            p.push_back(i);
        }
    }
    debug(p);
    while (int(p.size()) % k != 0) {
        p.pop_back();
    }
    debug(p);
    // avoid same element in one color
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });
    debug(p);
    vector<int> ans(n);
    for (int i = 0; i < int(p.size()); i++) {
        ans[p[i]] = i % k + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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