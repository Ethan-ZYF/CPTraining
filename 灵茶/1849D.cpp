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
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int l = 0, mx = 0;
    vector<array<int, 3>> inter;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (mx > 0) inter.push_back({l, i - 1, mx});
            l = i + 1;
            mx = 0;
        } else {
            mx = max(mx, a[i]);
        }
    }
    if (l < n) inter.push_back({l, n - 1, mx});
    int ans = inter.size();
    vector<int> b(n);
    for (auto& [l, r, mx] : inter) {
        for (int i = l; i <= r; i++)
            b[i] = 1;
        if (mx == 2) b[max(0, l - 1)] = 1, b[min(n - 1, r + 1)] = 1;
        if (mx == 1) {
            if (l > 0 and b[l - 1] == 0)
                b[l - 1] = 1;
            else
                b[min(n - 1, r + 1)] = 1;
        }
    }
    ans += count(b.begin(), b.end(), 0);
    cout << ans << '\n';
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