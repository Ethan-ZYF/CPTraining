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
    vector<pair<string, int>> a(n);
    map<string, i64> score, mp2;
    for (auto& [s, m] : a) {
        cin >> s >> m;
        score[s] += m;
    }
    i64 mx = *ranges::max_element(score | views::values);
    for (auto& [s, m] : a) {
        mp2[s] += m;
        if (mp2[s] >= mx && score[s] == mx) {
            cout << s << '\n';
            return;
        }
    }
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