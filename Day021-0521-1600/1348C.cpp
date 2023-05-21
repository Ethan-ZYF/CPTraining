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
    sort(s.begin(), s.end());
    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << '\n';
        return;
    }
    cout << s[0];
    if (s[k] != s[n - 1]) {
        for (int i = k; i < n; i++) {
            cout << s[i];
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < (n - k) / k; i++) {
        cout << s[n - 1];
    }
    if ((n - k) % k) {
        cout << s[n - 1];
    }
    cout << '\n';
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