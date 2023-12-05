#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

bool is_single_mount(vector<int>& a) {
    // 1 2 3 4 3 2 1 true
    // 4 3 2 1 2 3 4 false
    int n = a.size();
    int i = 0;
    while (i + 1 < n && a[i] < a[i + 1]) i++;
    while (i + 1 < n && a[i] > a[i + 1]) i++;
    return i + 1 == n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    bool ok = is_single_mount(a);
    cout << (ok ? "YES" : "NO") << '\n';
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