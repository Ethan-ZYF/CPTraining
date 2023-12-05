#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto& [t, v] : a)
        cin >> t >> v;
    sort(a.begin(), a.end());
    int pret = 0, prev = 0;
    bool ok = true;
    for (auto& [t, v] : a) {
        int dt = t - pret;
        int dv = v - prev;
        if (dt != dv and dt < v + 1) {
            ok = false;
            break;
        }
        pret = t;
        prev = v;
    }
    cout << (ok ? "Yes" : "No") << '\n';
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