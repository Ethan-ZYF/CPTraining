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
    vector<int> a(n), p(n);
    for (auto& x : a)
        cin >> x;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    int mx1i = p[n - 1], mx2i = p[n - 2];
    int mx1 = a[mx1i], mx2 = a[mx2i];
    vector<int> ans;
    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++) {
        if (i == mx1i) {
            if (sum - mx1 == 2 * mx2) {
                ans.push_back(i);
            }
        } else {
            if (sum - a[i] == 2 * mx1) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}