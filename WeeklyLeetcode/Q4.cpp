#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class T = i64>
struct Dijkstra {
    int n;
    const T INF;
    using pit = std::pair<int, T>;
    using G = std::vector<std::vector<pit>>;
    G g;
    std::vector<int> parent;

    Dijkstra(int n, const T& INF = 1e18) : n(n), g(n), INF(INF), parent(n, -1) {}

    void add(int a, int b, T c) {
        g[a].emplace_back(b, c);
    }

    std::vector<T> run(int s) {
        std::vector<T> d(n, INF);
        using pti = std::pair<T, int>;
        std::priority_queue<pti, std::vector<pti>, std::greater<>> q;
        d[s] = 0;
        q.emplace(d[s], s);
        while (q.size()) {
            auto [dist, u] = q.top();
            q.pop();
            if (dist != d[u])
                continue;
            for (auto& [v, w] : g[u]) {
                T fina = d[u] + w;
                if (d[v] > fina) {
                    d[v] = fina;
                    parent[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
        return d;
    }

    std::vector<int> get_path(int t) {
        std::vector<int> path;
        for (; t != -1; t = parent[t]) {
            path.push_back(t);
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    bool has_path(int t) {
        return parent[t] != -1;
    }
};

// [true,true,true,false,true,true,true,false]
// [true,true,true,false,true,true,true,false]
class Solution {
   public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> ans;
        Dijkstra<i64> d1(n), d2(n);
        for (auto& e : edges) {
            d1.add(e[0], e[1], e[2]);
            d1.add(e[1], e[0], e[2]);
            d2.add(e[1], e[0], e[2]);
            d2.add(e[0], e[1], e[2]);
        }
        auto d1s = d1.run(0);
        auto d2s = d2.run(n - 1);
        for (auto& e : edges)
            ans.push_back(d1s[e[0]] + d2s[e[1]] + e[2] == d1s[n - 1] or d1s[e[1]] + d2s[e[0]] + e[2] == d1s[n - 1]);
        return ans;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution sol;
    // nums = [2,3,5,7,7,7,5], andValues = [0,7,5]
    vector<int> nums = {2, 3, 5, 7, 7, 7, 5};
    vector<int> andValues = {0, 7, 5};
    return 0;
}