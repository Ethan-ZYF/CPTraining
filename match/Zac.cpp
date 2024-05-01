#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, a, b, L, R;
    cin >> n >> a >> b >> L >> R;
    for (int x = L; x <= R; x++) {
        if ((n - x * a - x / 2 * 3) % b == 0 and (n - x * a - x / 2 * 3) / b >= 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}