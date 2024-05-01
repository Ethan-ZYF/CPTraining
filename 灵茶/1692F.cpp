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
    array<int, 10> a{};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x % 10]++;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                a[i]--, a[j]--, a[k]--;
                if ((i + j + k) % 10 == 3 && a[i] >= 0 && a[j] >= 0 && a[k] >= 0) {
                    cout << "YES\n";
                    return;
                }
                a[i]++, a[j]++, a[k]++;
            }
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