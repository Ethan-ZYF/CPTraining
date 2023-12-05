#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

i64 f(int x, int y) {
    int g = gcd(x, y);
    x /= g;
    y /= g;
    return 1LL * x * 1e9 + y;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0, k = 0;
    map<long long, int> mp;
    for (char c : s) {
        if (c == 'D')
            d++;
        else
            k++;
        cout << ++mp[f(d, k)] << " ";
    }
    cout << "\n";
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