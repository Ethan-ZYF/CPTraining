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
    queue<int> a, b;
    int k1;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    int k2;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        b.push(x);
    }
    set<pair<queue<int>, queue<int>>> vis;
    auto dfs = [&](auto self, queue<int>& a, queue<int>& b, int w) -> void {
        debug(a);
        debug(b);
        if (a.empty()) {
            cout << w << " " << 2 << '\n';
            exit(0);
        }
        if (b.empty()) {
            cout << w << " " << 1 << '\n';
            exit(0);
        }
        if (vis.count({a, b})) {
            return;
        }
        vis.insert({a, b});
        int x = a.front();
        a.pop();
        int y = b.front();
        b.pop();
        if (x > y) {
            a.push(y);
            a.push(x);
        } else {
            b.push(x);
            b.push(y);
        }
        self(self, a, b, w + 1);
    };
    dfs(dfs, a, b, 0);
    cout << -1 << '\n';
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