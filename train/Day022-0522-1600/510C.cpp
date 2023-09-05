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
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    vector<vector<int>> g(26);
    vector<int> in(26);
    for (int i = 0; i < n - 1; i++) {
        int j = 0;
        while (j < s[i].size() and j < s[i + 1].size() and s[i][j] == s[i + 1][j]) j++;
        if (j == s[i].size()) continue;
        if (j == s[i + 1].size()) {
            cout << "Impossible\n";
            return;
        }
        int u = s[i][j] - 'a';
        int v = s[i + 1][j] - 'a';
        g[u].push_back(v);
        in[v]++;
    }
    debug(g, in);
    // topological sort
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (in[i] == 0) q.push(i);
    }
    string res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res += u + 'a';
        for (auto& v : g[u]) {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    if (res.size() != 26) {
        cout << "Impossible\n";
        return;
    }
    cout << res << '\n';
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