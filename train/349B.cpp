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
    vector<int> a(10, 1e9);
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
    }
    int mn = *min_element(a.begin(), a.end());
    int len = n / mn;
    if(len == 0){
        cout << -1;
    }
    debug(len);
    while (len--) {
        for (int j = 9; j; j--) {
            if (a[j] <= n and (n - a[j]) / mn == len) {
                cout << j;
                n -= a[j];
            }
        }
    }
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