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
    vector<int> a(n), depth(n);
    for (auto& x : a) cin >> x;
    int d = 0;
    depth[d] = 0;
    for (int i = 1; i < n; i++){
        if(i > 1 and a[i - 1] > a[i] ){
            d++;
        }
        depth[i] = depth[d] + 1;
        debug(i, d, depth[i]);
    }
    cout << depth.back() << '\n';
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