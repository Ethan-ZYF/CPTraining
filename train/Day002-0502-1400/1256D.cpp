#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<i64> a;
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '0') {
            a.push_back(i);
        }
    }
    if(a.empty()) {
        cout << s << '\n';
        return;
    }
    debug(a);
    i64 left = 0;
    for (auto& x : a) {
        i64 step = min(k, x - left);
        k -= step;
        x -= step;
        left++;
    }
    debug(a);
    string res(n, '1');
    for (auto& x : a) {
        res[x] = '0';
    }
    cout << res << '\n';
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