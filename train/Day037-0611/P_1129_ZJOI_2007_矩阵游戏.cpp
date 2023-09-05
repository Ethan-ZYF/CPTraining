#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
 * @author cuiaoxiang
 * https://codeforces.com/profile/cuiaoxiang
 */
struct Hungarian {
    int n;
    std::vector<std::vector<int>> a;
    std::vector<int> d;
    std::vector<bool> visit;
    bool path(int u) {
        for (auto& v : a[u]) {
            if (visit[v]) continue;
            visit[v] = true;
            if (d[v] < 0 || path(d[v])) {
                d[v] = u;
                return true;
            }
        }
        return false;
    }
    Hungarian(int n, int m) : n(n), a(n), d(m, -1), visit(m) {}
    void add(int x, int y) {
        a[x].push_back(y);
    }
    int solve() {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            std::fill(visit.begin(), visit.end(), false);
            ret += path(i);
        }
        return ret;
    }
};

void solve() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto& v : a) {
        for (auto& x : v) {
            cin >> x;
        }
    }

    Hungarian hungarian(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                hungarian.add(i, j);
            }
        }
    }
    auto ans = hungarian.solve();
    cout << (ans == n ? "Yes" : "No") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}