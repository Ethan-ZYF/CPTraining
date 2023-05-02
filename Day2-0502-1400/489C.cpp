#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


void solve() {
    int n, m;
    cin >> n >> m;
    if(n == 1 and m == 0){
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    string mn(n, '0'), mx(n, '0');
    int s1 = m, s2 = m;
    mn[0] = '1';
    s1--;
    if(s1 < 0){
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    for (int i = n - 1; i > 0; i--){
        int x = min(s1, 9);
        mn[i] = x + '0';
        s1 -= x;
    }
    if (s1 >= 9){
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    mn[0] += s1;
    debug(mn);
    mx[0] = min(s2, 9) + '0';
    s2 -= min(s2, 9);
    for (int i = 1; i < n; i++){
        int x = min(s2, 9);
        mx[i] = x + '0';
        s2 -= x;
    }
    debug(mx);
    if (s2){
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    cout << mn << ' ' << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}