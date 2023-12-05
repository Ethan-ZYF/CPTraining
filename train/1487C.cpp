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
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (j - i <= n / 2)
                    cout << 1 << " ";
                else
                    cout << -1 << " ";
        cout << endl;
    } else {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (j - i < n / 2)
                    cout << 1 << " ";
                else if (j - i == n / 2)
                    cout << 0 << " ";
                else
                    cout << -1 << " ";
        cout << endl;
    }
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