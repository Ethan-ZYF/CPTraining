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
    for (auto& x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            i++;
            j++;
            ans++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << '\n';
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