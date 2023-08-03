#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int P = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    i64 ans = 0;
    bool flag = false;
    for (auto x : a) {
        if (!flag) {
            if (ans + x > ans * x) {
                ans = (ans + x);
            } else {
                ans = (ans * x);
            }
            if (ans >= 2) {
                flag = true;
                ans = ans % P;
            }¡
        } else {
            if (x <= 1) {
                ans = (ans + x) % P;
            } else {
                ans = (ans * x) % P;
            }
        }
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