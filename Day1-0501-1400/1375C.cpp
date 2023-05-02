#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

// 1 2 3 4 YES
// 1 ..... YES
// 2 1 3 4 YES
// 2 1 ... YES
// 3 1 ... YES
// 4 1 2 3 NO
// 4 1 ... NO
// 4 2 1 5 3  NO
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << (a[0] < a[n - 1] ? "YES" : "NO") << '\n';
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