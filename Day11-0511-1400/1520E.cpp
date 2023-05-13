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
    string s;
    cin >> s;
    vector<int> a;
    int empty = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            empty++;
        } else {
            a.push_back(empty);
        }
    }
    debug(a);
    int mid = (a.size() - 1) / 2;
    debug(mid);
    i64 ans = 0;
    for (auto x : a) {
        // 需要挪动 x - a[mid] 个点(.)到中间
        ans += abs(x - a[mid]);
    }
    cout << ans << "\n";
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