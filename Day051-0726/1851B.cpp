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

    vector<int> b = a;
    for (auto& x : b) x = x & 1;

    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            c.push_back(even.back());
            even.pop_back();
        } else {
            c.push_back(odd.back());
            odd.pop_back();
        }
    }
    auto ans = is_sorted(c.begin(), c.end());
    cout << (ans ? "YES" : "NO") << '\n';
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