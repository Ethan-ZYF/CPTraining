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
    for (auto &x : a) cin >> x;
    vector<pair<int, int>> c;
    if (a.back() == 1) {
        cout << "NO" << endl;
        return;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            if (cnt1) {
                c.emplace_back(cnt0, cnt1);
                cnt1 = 0;
                cnt0 = 0;
            }
            cnt0++;
        } else {
            cnt1++;
        }
    }
    if (cnt1) {
        c.emplace_back(cnt0, cnt1);
        cnt1 = 0;
        cnt0 = 0;
    }
    debug(c);
    debug(cnt0, cnt1);
    cout << "YES" << endl;
    for (auto &[x, y] : c) {
        for (int i = 0; i < x + y - 1; i++) {
            cout << 0 << ' ';
        }
        cout << y << ' ';
    }
    for (int i = 0; i < cnt0; i++) {
        cout << 0 << ' ';
    }
    cout << endl;
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