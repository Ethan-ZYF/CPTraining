#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> xy;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        xy.emplace(x, y);
    }
    map<char, pair<int, int>> dir = {
        make_pair('U', make_pair(0, 1)),
        make_pair('D', make_pair(0, -1)),
        make_pair('L', make_pair(-1, 0)),
        make_pair('R', make_pair(1, 0)),
    };
    pair<int, int> cur = make_pair(0, 0);
    for (auto c : s) {
        auto [dx, dy] = dir[c];
        cur.first += dx;
        cur.second += dy;
        if(h == 0){
            cout << "No\n";
            return;
        }
        h--;
        if (h < k and xy.count(cur)) {
            h = k;
            xy.erase(cur);
        }
    }
    cout << "Yes\n";
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