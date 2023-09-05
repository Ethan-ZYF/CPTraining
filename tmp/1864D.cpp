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
    vector a(n, vector(n, 0)), b(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = a[i][j];
            a[i][j] ^= b[i][j];
            ans += a[i][j];
            if (i + 1 < n) {
                a[i + 1][j] ^= tmp;
                if (j - 1 >= 0) {
                    b[i + 1][j - 1] ^= tmp;
                } else if (i + 2 < n) {
                    b[i + 2][j] ^= tmp;
                }
                if (j + 1 < n) {
                    b[i + 1][j + 1] ^= tmp;
                } else if (i + 2 < n) {
                    b[i + 2][j] ^= tmp;
                }
                if (i + 2 < n) {
                    b[i + 2][j] ^= tmp;
                }
            }
            b[i][j] = 0;
        }
    }
    cout << ans << "\n";
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