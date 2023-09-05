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
    for (auto& x : a) cin >> x;

    i64 sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << '\n';
        return;
    }
    i64 target = sum / 3;
    i64 cur = 0, cnt = 0, ans = 0;
    for (int r = 0; r < n - 1; r++){
        cur += a[r];
        if(cur != 2 * target){
            if (cur == target) cnt++;
            continue;
        }
        ans += cnt;
        if (cur == target) cnt++;
    }
    cout << ans << '\n';
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