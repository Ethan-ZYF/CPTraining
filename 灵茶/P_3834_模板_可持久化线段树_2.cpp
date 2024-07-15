#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct WaveletTree {
    using iter = vector<int>::iterator;
    vector<vector<int>> c;
    const int SIGMA;

    WaveletTree(vector<int> a, int sigma) : c(sigma * 2), SIGMA(sigma) {
        build(a.begin(), a.end(), 0, SIGMA, 1);
    }

    void build(iter begin, iter end, int l, int r, int u) {
        if (r - l == 1) return;
        int m = (l + r) / 2;

        c[u].reserve(end - begin + 1);
        c[u].push_back(0);
        for (auto it = begin; it != end; ++it) {
            c[u].push_back(c[u].back() + (*it < m));
        }

        auto p = stable_partition(begin, end, [=](int i) { return i < m; });
        build(begin, p, l, m, 2 * u);
        build(p, end, m, r, 2 * u + 1);
    }

    // occurrences of val in position[0, i)
    int rank(int val, int i) const {
        if (val < 0 or val >= SIGMA) return 0;

        int l = 0, r = SIGMA, u = 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (val < m) {
                i = c[u][i], r = m;
                u = u * 2;
            } else {
                i -= c[u][i], l = m;
                u = u * 2 + 1;
            }
        }
        return i;
    }

    int quantile(int k, int i, int j) const {
        assert(k > 0 && k <= j - i);
        int l = 0, r = SIGMA, u = 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int ni = c[u][i], nj = c[u][j];
            if (k <= nj - ni) {
                i = ni, j = nj, r = m;
                u = 2 * u;
            } else {
                k -= nj - ni;
                i -= ni, j -= nj, l = m;
                u = 2 * u + 1;
            }
        }
        return l;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    auto b = a, c = a;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    auto find = [&](int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    };
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        b[i] = find(b[i]);
        mp[b[i]] = c[i];
    }

    WaveletTree wt(b, *max_element(b.begin(), b.end()) + 1);

    while (q--) {
        int k, l, r;
        cin >> l >> r >> k;
        l--;
        cout << mp[wt.quantile(k, l, r)] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}