#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int A, B, n;
    cin >> A >> B >> n;
    vector<int> a(n), b(n);
    map<int, int> ca, cb;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ca[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cb[b[i]]++;
    }
    i64 res = 0;
    for (int i = 0; i < n; i++){
        int x = n - ca[a[i]] - cb[b[i]] + 1;
        res += x;
    }
    cout << res / 2 << '\n';
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