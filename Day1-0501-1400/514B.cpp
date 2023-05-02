#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, X, Y;
    cin >> n >> X >> Y;
    vector<pair<int, int>> coords(n);
    for (auto& [x, y] : coords)
        cin >> x >> y;
    debug(coords);
    set<pair<int, int>> slope;
    for (auto [x, y] : coords) {
        int dx = x - X;
        int dy = y - Y;
        if (dx == 0) {
            slope.emplace(0, 1);
        } else {
            auto g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            slope.emplace(dx, dy);
        }
    }
    debug(slope);
    cout << slope.size() << '\n';
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