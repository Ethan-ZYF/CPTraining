#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
map<i64, int> factor(i64 n) {
    map<i64, int> res;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res[i] = 0;
            while (n % i == 0) {
                res[i]++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        res[n] = 1;
    }
    return res;
}

map<i64, int> operator+(const map<i64, int>& a, const map<i64, int>& b) {
    map<i64, int> res = a;
    for (auto [p, e] : b) {
        res[p] += e;
    }
    return res;
}

void solve() {
    i64 n, q;
    cin >> n >> q;
    auto fn = factor(n);
    auto start = fn;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            i64 x;
            cin >> x;
            auto fx = factor(x);
            auto f = fn + fx;
            fn = f;
            i64 dn = 1;
            for (auto [p, e] : f) {
                dn *= (e + 1);
            }
            auto fdn = factor(dn);
            bool flag = true;
            for (auto [p, e] : fdn) {
                if (e > fn[p]) {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << '\n';
        } else {
            fn = start;
        }
    }
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