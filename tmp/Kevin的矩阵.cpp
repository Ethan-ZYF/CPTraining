#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    int ans = 1e9;
    auto get = [&](int kuan) -> int {
        int ans = 1e9;
        for (int i = 0; i < min(kuan, n); i++) {
            int cnt = 0;
            for (int j = 0; j * kuan + i < n; j++) {
                if (a[j * kuan + i] != k) {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    };
    ans = min(ans, get(m));
    int up = sqrt(n);
    for (int cols = max(1, m - 2 * up); cols <= m + 2 * up; cols++) {
        ans = min(ans, get(cols) + abs(cols - m));
    }
    cout << ans << endl;
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