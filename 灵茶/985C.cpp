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
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector<int> a(m);
    for (int& x : a) {
        cin >> x;
    }

    rgs::sort(a);
    int u = rgs::upper_bound(a, a[0] + l) - a.begin();
    if (u < n) {
        cout << 0 << '\n';
        return;
    }
    i64 ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        ans += a[cur];
        cur++;
        for (int j = 1; j < k; j++) {
            //* u - cur: 剩下的板子， i + 1: 已经造出来的桶， n - (i + 1): 缺的桶
            if (u - cur > n - (i + 1))
                cur++;
            else
                break;
        }
    }
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