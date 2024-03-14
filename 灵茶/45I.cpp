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
    vector<int> a;
    cin >> n;
    int t = 0;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            zero++;
            continue;
        }
        if (x > 0)
            cout << x << " ", t++;
        if (x < 0)
            a.push_back(x);
    }
    ranges::sort(a);
    for (int i = 0; i < ssize(a); i += 2) {
        if (i + 1 < ssize(a)) {
            cout << a[i] << " " << a[i + 1] << " ";
            t += 2;
        }
    }
    if (zero && t == 0) {
        cout << 0;
    } else if (t == 0) {
        cout << a.back();
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();

    return 0;
}