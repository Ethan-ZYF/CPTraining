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
    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '#') continue;
            int cnt = 0;
            if (i > 0 && grid[i - 1][j] == '#') cnt++;
            if (i < n - 1 && grid[i + 1][j] == '#') cnt++;
            if (j > 0 && grid[i][j - 1] == '#') cnt++;
            if (j < m - 1 && grid[i][j + 1] == '#') cnt++;
            if(cnt >= 2){
                cout << i + 1 << ' ' << j + 1 << endl;
                return;
            }
        }
    }
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