#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < m; i++) {
        pq.emplace(0, i + 1);
    }
    vector<int> ans(n);
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        auto [x, id] = pq.top();
        pq.pop();
        ans[a[i].second] = id;
        pq.emplace(x + a[i].first, id);
    }
    debug(ans);
    vector<int> tmp;
    while (!pq.empty()) {
        tmp.push_back(pq.top().first);
        pq.pop();
    }
    if (*tmp.begin() - *tmp.rbegin() > d) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto& x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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