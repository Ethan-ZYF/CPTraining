#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
    return {};
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a = solve3(n - k + 3);
    for (int i = 0; i < k - 3; i++) a.push_back(1);
    for (auto& x : a) cout << x << ' ';
    cout << '\n';
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