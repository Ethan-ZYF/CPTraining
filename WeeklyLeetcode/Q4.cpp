#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

class Solution {
   public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<array<i64, 2>> dp(n);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        auto dfs = [&](auto&& self, int u, int p) -> void {
            for (int v : g[u]) {
                if (v == p)
                    continue;
                self(self, v, u);
            }
            dp[u][0] = max(dp[u][0], dp[u][1] + nums[u]);
            dp[u][1] = max(dp[u][1], dp[u][0] + (nums[u] ^ k));
        };
        dfs(dfs, 0, -1);
        return max(dp[0][0], dp[0][1]);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution sol;
    return 0;
}