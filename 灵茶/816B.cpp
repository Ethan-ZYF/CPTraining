#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 2e5 + 5;
void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(INF);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    
    partial_sum(a.begin(), a.end(), a.begin());
    ranges::transform(a, a.begin(), [k](int x) { return x >= k; });
    partial_sum(a.begin(), a.end(), a.begin());

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
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