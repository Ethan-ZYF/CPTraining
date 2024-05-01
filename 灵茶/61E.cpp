#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <typename T = int>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n = 0) : n(n), a(n, T()) {}

    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& it : a) {
        cin >> it;
    }

    vector<i64> b = a;
    sort(b.begin(), b.end());

    vector<i64> p1(n), p2(n);
    Fenwick<i64> f(n);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        p1[i] = f.sum(pos, n);
        f.add(pos, 1);
    }
    f = Fenwick<i64>(n);
    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        p2[i] = f.sum(pos);
        f.add(pos, 1);
    }
    debug(p1);
    debug(p2);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p1[i] * p2[i];
    }
    cout << ans << '\n';
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