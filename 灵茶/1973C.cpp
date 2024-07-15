#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> q(n);
    int nid = find(p.begin(), p.end(), n) - p.begin();
    if (!(nid & 1)) {
        vector<pair<int, int>> v;
        for (int i = 1; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[0], 0});
        for (int i = 2; i < n; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    } else {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[n - 1], n - 1});
        for (int i = 1; i < n - 1; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cout << q[i] << " \n"[i == n - 1];
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