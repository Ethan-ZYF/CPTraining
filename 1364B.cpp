#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (auto& x : a)
        cin >> x;

    b.push_back(a[0]);
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            b.push_back(a[i]);
        }
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            b.push_back(a[i]);
        }
    }
    b.push_back(a[n - 1]);
    cout << b.size() << '\n';
    for (auto x : b)
        cout << x << ' ';
    cout << '\n';
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