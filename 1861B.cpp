#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    auto check = [&](int mid) -> bool {
        if (a[mid] == '0' and b[mid] == '0' and a[mid + 1] == '1' and b[mid + 1] == '1')
            return true;
        return false;
    };
    for (int i = 0; i < n - 1; i++) {
        if (check(i)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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