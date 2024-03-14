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
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<int> q;
        auto dfs = [&](auto&& self, int u, int fa, int rt, i64 val) -> int {
            int tmp = val % k == 0;
            for (auto [v, w] : g[u]) {
                if (v == fa)
                    continue;
                if (u == rt) {
                    q.push_back(self(self, v, u, rt, w));
                }
                tmp += self(self, v, u, rt, val + w);
            }
            return tmp;
        };
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int tot = 0, cur = 0;
            q.clear();
            dfs(dfs, i, -1, i, 0);
            for (int x : q) {
                tot += x * cur;
                cur += x;
            }
            ans[i] = tot;
        }
        return ans;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
    int k = 1;
    Solution sol;
    auto ans = sol.countPairsOfConnectableServers(edges, k);
    debug(ans);
    // edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
    edges = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
    k = 3;
    ans = sol.countPairsOfConnectableServers(edges, k);
    debug(ans);
    return 0;
}