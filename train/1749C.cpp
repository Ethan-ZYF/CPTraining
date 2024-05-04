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
    for (int& x : a) {
        cin >> x;
    }

    auto check = [&](int k) -> bool {
        multiset<int> s;
        for (auto y : a)
            s.insert(y);
        debug(k);
        debug(k, s);
        while (k and s.size()) {
            auto up = s.upper_bound(k);
            if (up == s.begin()) {
                debug(false);
                return false;
            }
            up--;
            s.extract(*up);
            if (s.empty()) {
                debug(true);
                return true;
            }
            int x = *s.begin();
            s.extract(x);
            s.insert(x + k);
            debug(k, s);
            k--;
        }
        debug(true);
        return true;
    };

    int lo = -1, hi = n + 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';
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