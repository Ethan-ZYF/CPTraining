#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
//  0: 0000
//  1: 0001 1
//  2: 0010 2
//  3: 0011 1
//  4: 0100 3
//  5: 0101 1
//  6: 0110 2
//  7: 0111 1
//  8: 1000 4
//  9: 1001 1
// 10: 1010 2
// 11: 1011 1
// 12: 1100 3
// 13: 1101 1
// 14: 1110 2
// 15: 1111 1

i64 calc(i64 x) {
    // x is power of 2
    debug(x);
    assert((x & (x - 1)) == 0);
    i64 ans = 0;
    while (x >= 1) {
        ans += x;
        x /= 2;
    }
    return ans;
}

void solve() {
    i64 n;
    cin >> n;
    i64 ans = 0;
    // while (n) {
    //     i64 x = 1;
    //     while (x <= n) {
    //         x *= 2;
    //     }
    //     x /= 2;
    //     ans += calc(x);
    //     n -= x;
    // }
    while(n){
        ans += n;
        n /= 2;
    }
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