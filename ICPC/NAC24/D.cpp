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
    vector<int> a(n), b(m);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;

    vector<int> a1(2 * n), a2(2 * n);
    for (int i = 0; i < n; i++) {
        a1[i] = a1[i + n] = a[i];
        a2[i] = a2[i + n] = a[i];
    }
    reverse(a2.begin(), a2.end());

    int i = find(a1.begin(), a1.end(), b[0]) - a1.begin();
    int j = 0;
    while (a1[i] == b[j] && j < m) {
        i++;
        j++;
    }
    bool ans1 = j == m;
    i = find(a2.begin(), a2.end(), b[0]) - a2.begin();
    j = 0;
    while (a2[i] == b[j] && j < m) {
        i++;
        j++;
    }
    bool ans2 = j == m;
    cout << (ans1 || ans2 ? "1" : "0") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}