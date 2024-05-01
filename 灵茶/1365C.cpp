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
    vector<int> a(n), b(n);
    for (int& x : a)
        cin >> x;
    for (int& x : b)
        cin >> x;

    vector<int> posa(n), posb(n);
    for (int i = 0; i < n; i++) {
        posa[a[i] - 1] = i;
        posb[b[i] - 1] = i;
    }

    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int diff = posb[i] - posa[i];
        if (diff < 0) {
            diff += n;
        }
        cnt[diff]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
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