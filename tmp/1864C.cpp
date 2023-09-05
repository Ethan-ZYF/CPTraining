#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int lowbit(int x) {
    return x & -x;
}

void solve() {
    int x;
    cin >> x;
    vector<int> ans;
    ans.push_back(x);
    int y = lowbit(x);
    while (x != y) {
        x -= y;
        ans.push_back(x);
        y = lowbit(x);
    }
    while (x != 1) {
        x >>= 1;
        ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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