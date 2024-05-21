#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int div_ceil(int a, int b) {
    return ceil(1.0 * a / b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(k);
    for (auto& x : s) {
        cin >> x;
    }
    if (k == 1) {
        cout << "Yes\n";
        return;
    }
    vector<int> a(n);
    int i = n - 1;
    for (int j = k - 1; j > 0; j--) {
        a[i] = s[j] - s[j - 1];
        i--;
    }
    bool flag = is_sorted(a.begin() + i + 1, a.end());
    int top = s[0];
    int base = div_ceil(top, i + 1);
    debug(flag, i, base, a);
    cout << (flag and base <= a[i + 1] ? "Yes" : "No") << '\n';
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