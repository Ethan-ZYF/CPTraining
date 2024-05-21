#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int segs = (n + k - 1) / k;
    int last = n % k;
    int cnt = 0;
    debug(segs, last);
    for (int i = 0; i < m; i++) {
        if (a[i] == segs) {
            cnt++;
        } else if (a[i] > segs) {
            cout << "NO\n";
            return;
        }
    }
    debug(cnt);
    cout << (cnt <= last or last == 0 ? "YES" : "NO") << '\n';
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