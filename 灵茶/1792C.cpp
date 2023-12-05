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
    vector<int> a(n), pos(n + 1);
    int i = 0;
    for (auto& x : a) {
        cin >> x;
        pos[x] = i++;
    }
    int x = n / 2;
    while (pos[x] < pos[x + 1] and pos[n - x] < pos[n - x + 1]) {
        x--;
    }
    cout << x << '\n';
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