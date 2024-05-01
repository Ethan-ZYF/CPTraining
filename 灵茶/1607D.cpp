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
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    string s;
    cin >> s;

    vector<pair<char, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {s[i], a[i]};
    }
    sort(p.begin(), p.end());

    bool ok = true;
    int i = 1;
    for (auto [c, x] : p) {
        if (c == 'B') {
            if (x < i) {
                ok = false;
            }
        } else {
            if (x > i) {
                ok = false;
            }
        }
        i++;
    }
    cout << (ok ? "YES" : "NO") << '\n';
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