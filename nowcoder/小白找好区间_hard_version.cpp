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

    T rangeSum(int l, int r) {
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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n), psa(n + 1), psb(n + 1), c(n + 1), d(n + 1), pc(n + 1);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "byl")
            a[i] = 1;
        else
            b[i] = 1;
    }
    partial_sum(a.begin(), a.end(), psa.begin() + 1);
    partial_sum(b.begin(), b.end(), psb.begin() + 1);
    // a[r] - a[l] > k * (b[r] - b[l])
    // a[r] - k * b[r] > a[l] - k * b[l]
    for (int i = 0; i <= n; i++) {
        c[i] = psa[i] - k * psb[i];
    }
    d = c;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int i = 0; i <= n; i++) {
        pc[i] = lower_bound(c.begin(), c.end(), d[i]) - c.begin();
    }

    debug(c);
    debug(d);
    debug(pc);

    i64 ans = 0;
    Fenwick<i64> f(n + 1);
    for (int i = 0; i <= n; i++) {
        ans += f.sum(pc[i]);
        f.add(pc[i], 1);
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