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
    vector<int> res;
    while (n) {
        string sn = to_string(n);
        string t = sn;
        for (auto& x : t) {
            x = min(x, '1');
        }
        int m = stoi(t);
        n -= m;
        res.push_back(m);
    }
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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