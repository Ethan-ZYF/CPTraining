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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](auto&& self, int l, int r, int x) -> bool {
        if (l >= r) return true;
        int pos = find(a.begin() + l, a.begin() + r, x) - a.begin();
        int y = x;
        for (int i = pos; i < r; i++) {
            if (a[i] != y) {
                return false;
            }
            y++;
        }
        while(pos > l && a[pos - 1] == y) {
            pos--;
            y++;
        }
        return self(self, l, pos, y);
    };
    auto res = check(check, 0, n, 1);
    cout << (res ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}