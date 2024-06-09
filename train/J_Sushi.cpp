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
    array<int, 4> cnt{};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector dp(301, vector(301, vector<double>(301)));

    auto dfs = [&](auto&& self, int x, int y, int z) -> double {
        if (x < 0 || y < 0 || z < 0) return 0;
        if (x == 0 and y == 0 and z == 0) return 0;
        if (dp[x][y][z] != 0) return dp[x][y][z];
        double res = n;
        res += x * self(self, x - 1, y, z);
        res += y * self(self, x + 1, y - 1, z);
        res += z * self(self, x, y + 1, z - 1);
        res /= x + y + z;
        return dp[x][y][z] = res;
    };

    cout << setprecision(10) << dfs(dfs, cnt[1], cnt[2], cnt[3]) << '\n';
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