#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = true;
    for (int a = 0; a < k; ++a) {
        bool a1 = false, a0 = false;
        for (int i = a; i < n; i += k) {
            if (s[i] == '1') {
                a1 = true;
            } else if (s[i] == '0') {
                a0 = true;
            }
        }
        if (a0 && a1) {
            ok = false;
        } else if (a0 || a1) {
            for (int i = a; i < n; i += k)
                s[i] = a0 ? '0' : '1';
        }
    }
    if (not ok) {
        cout << "NO\n";
        return;
    }
    s = s.substr(0, k);
    int cnt0 = ranges::count(s, '0');
    int cnt1 = ranges::count(s, '1');
    if (cnt0 > k / 2 or cnt1 > k / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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