#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

//* given a directed graph, edges are unweighted
//* each node has a value, you can perform one 'buy' operation and one 'sell' operation
//* you want to maximize the profit, but you can only sell after you buy
//* you must start at node 0 and end with node n - 1, you can visit a node multiple times

//! n, m
//! a1, a2, ..., an
//! x1, y1, z1
//! x2, y2, z2
//! ...
//! xm, ym, zm

//! zi = 1: directed edge from xi to yi
//! zi = 2: bidirectional edge between xi and yi

const int MX = 1 << 18;
const int INF = 1e9 + 100;
int n, m;
int a[MX];
int dist[MX][3];
/*
 *  max(a[i] - a[j]) = min(-a[i] - (-a[j])) = min(a[j] - a[i])
    First, negate all a[i] to try to find the MINIMUM instead of maximum

    dist[v][0] = min cost to get to v and not buy or sell anything
    dist[v][1] = min cost to get to v, having bought something already
    dist[v][2] = min cost to get to v, having bought and sold already

    the answer is -dist[n-1][2]
*/

vector<int> adj[MX];

set<array<int, 3>> pq;

void relax(int v, int t, int d) {
    if (d < dist[v][t]) {
        pq.erase({dist[v][t], v, t});
        dist[v][t] = d;
        pq.insert({dist[v][t], v, t});
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= -1;
    }

    for (int i = 0; i < m; i++) {
        int v, u, tp;
        cin >> v >> u >> tp;
        --v;
        --u;
        adj[v].push_back(u);

        if (tp == 2) {
            adj[u].push_back(v);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dist[i][j] = INF;
        }
    }

    relax(0, 0, 0);

    while (!pq.empty()) {
        auto [d, v, t] = *pq.begin();
        pq.erase(pq.begin());

        for (int u : adj[v])
            relax(u, t, d);

        if (t == 0) {
            // buy and sell both here
            relax(v, 2, d);

            // buy here
            relax(v, 1, d - a[v]);
        }

        if (t == 1) {
            // sell here
            relax(v, 2, d + a[v]);
        }
    }

    cout << -dist[n - 1][2] << endl;
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