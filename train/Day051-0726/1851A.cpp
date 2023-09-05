#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m,k, H;
    cin >> n >> m >> k >> H;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int ans = 0;
    for(int x : a){
        int diff = abs(x - H);
        if(diff % k == 0 and diff / k < m and diff / k > 0){
            ans++;
        }
    }
    cout << ans << '\n';
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