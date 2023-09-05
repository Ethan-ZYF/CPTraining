#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    bool ok = true;
    for (auto& gi : g) {
        cin >> gi;
        int cu = ranges::count(gi, 'U');
        int cd = ranges::count(gi, 'D');
        if (cu % 2 or cd % 2) ok = false;
    }
    for (int j = 0; j < m; j++) {
        int cl = 0, cr = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == 'L') cl++;
            if (g[i][j] == 'R') cr++;
        }
        if (cl % 2 or cr % 2) ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    vector<string> ans(n, string(m, '.'));
    string choice = "WB";
    for (int i = 0; i < n; i++) {
        int iu = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'U') {
                ans[i][j] = choice[iu];
                iu ^= 1;
                ans[i + 1][j] = choice[iu];
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int il = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == 'L') {
                ans[i][j] = choice[il];
                il ^= 1;
                ans[i][j + 1] = choice[il];
            }
        }
    }
    for (auto& ai : ans) cout << ai << "\n";
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