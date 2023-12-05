#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    multiset<int> s;
    vector<i64> ans = b;
    for (int i = 0; i < n; i++) {
        int j = idx[i];
        auto cur = s.rbegin();
        int cnt = 0;
        while (cur != s.rend() && cnt < k) {
            ans[j] += *cur;
            cur++;
            cnt++;
        }
        s.insert(b[j]);
    }
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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