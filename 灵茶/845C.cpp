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
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    sort(a.begin(), a.end());
    multiset<int> s;
    for (auto [x, y] : a) {
        if (s.size() and *s.begin() < x)
            s.extract(s.begin());
        s.insert(y);
    }
    cout << (s.size() <= 2 ? "YES" : "NO") << '\n';
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