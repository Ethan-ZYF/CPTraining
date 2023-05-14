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
    sort(a.begin(), a.end(), [&](i64 x, i64 y) {
        i64 cntx3 = 0, cnty3 = 0;
        while (x % 3 == 0) {
            x /= 3;
            cntx3++;
        }
        while (y % 3 == 0) {
            y /= 3;
            cnty3++;
        }
        if (cntx3 != cnty3) return cntx3 > cnty3;
        i64 cntx2 = 0, cnty2 = 0;
        while (x % 2 == 0) {
            x /= 2;
            cntx2++;
        }
        while (y % 2 == 0) {
            y /= 2;
            cnty2++;
        }
        return cntx2 < cnty2;
    });
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}