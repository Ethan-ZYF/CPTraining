#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    int n = n0 + n1 + n2 + 1;
    string s(n, '1');
    for (int i = 1; i <= n0; i++) {
        s[i] = '0';
        s[i - 1] = '0';
    }
    debug(s);
    if (s[0] == '0') {
        n1--;
    }

    int j = 0;
    int pos = s.find('1', 0);
    for (int i = pos + 1; i < n, j + 1 < n1; i += 2, j += 2) {
        s[i] = '0';
    }
    if (j != n1) s.back() = '0';
    debug(s);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' and s[i + 1] == '1') cnt++;
    }
    assert(cnt == n2);
    cout << s << '\n';
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