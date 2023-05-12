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
    if (k != n - 1) {
        if (k == 0) {
            for (int i = 0; i < n / 2; i++) {
                cout << i << ' ' << n - i - 1 << '\n';
            }
        } else {
            cout << 0 << ' ' << n - k - 1 << '\n';
            cout << k << ' ' << n - 1 << '\n';
            for (int i = 1; i < n / 2; i++){
                if(i != k and i != n - k - 1)
                    cout << i << ' ' << n - i - 1 << '\n';
            }
        }
    }else{
        if(n == 4){
            cout << -1 << '\n';
        }else{
            cout << n - 1 << ' ' << n - 2 << '\n';
            cout << 1 << ' ' << 3 << '\n';
            cout << 0 << ' ' << n - 4 << '\n';
            for (int i = 2; i < n / 2; i++){
                if(i != 3)
                    cout << i << ' ' << n - i - 1 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
        // cout << endl;
    }

    return 0;
}