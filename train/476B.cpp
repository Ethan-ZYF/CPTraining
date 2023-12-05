#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> c1, c2;
    for (auto c : s1) c1[c]++;
    for (auto c : s2) c2[c]++;
    for (auto c : c2) {
        if (c1[c.first] < c.second) {
            cout << 0 << '\n';
            return;
        }
        c1[c.first] -= c.second;
    }
    
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