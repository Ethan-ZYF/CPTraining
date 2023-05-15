#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i64 n, s;
    cin >> n >> s;
    string sn = to_string(n);
    i64 sum = 0;
    for (auto& x : sn) {
        sum += x - '0';
    }
    if (sum <= s) {
        cout << 0 << '\n';
        return;
    }
    i64 ans = 0;
    i64 pow = 1;
    reverse(sn.begin(), sn.end());
    for (int i = 0; i < sn.size(); i++) {
        if (sn[i] == '0') {
            pow *= 10;
            continue;
        }
        ans += pow * (10 - (sn[i] - '0'));
        sum -= sn[i] - '0';
        sn[i] = '0';
        sn[i + 1]++;
        sum++;
        pow *= 10;
        if (sum <= s) {
            break;
        }
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