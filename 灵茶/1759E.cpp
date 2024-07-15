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
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    rgs::sort(a);

    vector<vector<int>> p = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
    int ans = 0;
    for (auto& v : p) {
        int cur = 0;
        i64 points = h;
        int i = 0;
        for (auto x : a) {
            while (i < 3 and points <= x)
                points *= v[i++];
            if (points <= x) break;
            points += x / 2;
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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