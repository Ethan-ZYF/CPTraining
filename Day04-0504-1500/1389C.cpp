#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int f(const string& s, int x, int y) {
    int res = 0;
    for (const char& c : s)
        if (c - '0' == x) {
            res++;
            swap(x, y);
        }
    if (x != y && res % 2 == 1)
        res--;
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size(), ans = n;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ans = min(ans, n - f(s, i, j));
    cout << ans << '\n';
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