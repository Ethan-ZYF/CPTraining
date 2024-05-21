#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    string ans;
    int mask = 0, target = (1 << k) - 1;
    for (auto c : s) {
        mask |= 1 << (c - 'a');
        if (mask == target) {
            ans += c;
            mask = 0;
        }
    }
    debug(ans);
    if (ans.size() >= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";

        for (int i = 0; i < k; i++) {
            if (!(mask & (1 << i))) {
                ans += 'a' + i;
                break;
            }
        }
        while (ans.size() < n)
            ans += 'a';
        cout << ans << '\n';
    }
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