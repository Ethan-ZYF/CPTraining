#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int b = 0;
    vector<int> a;
    int cnt = 0;
    for (auto c : s) {
        if (c == 'B') {
            b++;
            if (cnt)
                a.push_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt) a.push_back(cnt);
    debug(b);
    debug(a);
    if (a.size() <= b) {
        cout << n - b;
    } else {
        cout << n - b - ranges::min(a);
    }
    cout << '\n';
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