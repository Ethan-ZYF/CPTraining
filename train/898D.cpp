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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    rgs::sort(a);

    int l = 0, ans = 0, cnt = 0;
    for (int r = 0; r < n; r++) {
        cnt++;
        while (a[r] - a[l] >= m) {
            if (a[l]) {
                cnt--;
            }
            l++;
        }
        if (cnt == k) {
            a[r] = 0;
            ans++;
            cnt--;
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