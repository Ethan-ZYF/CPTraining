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
    sort(b.begin(), b.end());
    multiset<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.insert(b[i]);
        } else {
            odd.insert(b[i]);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            auto it = even.find(a[i]);
            if (it == even.end()) {
                ok = false;
                break;
            }
            even.erase(it);
        } else {
            auto it = odd.find(a[i]);
            if (it == odd.end()) {
                ok = false;
                break;
            }
            odd.erase(it);
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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