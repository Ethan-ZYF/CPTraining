#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct ChairTree {
    int tot, n, mxv;
    vector<int> rs, ls, root;
    vector<i64> sum;

    ChairTree() {}

    ChairTree(int n_, int mxv_) {
        init(n_, mxv_);
    }

    void init(int n_, int mxv_) {
        n = n_ + 1;
        mxv = mxv_ + 1;
        tot = 0;
        rs.resize(1, 0);
        ls.resize(1, 0);
        sum.resize(1, 0);
        root.resize(n, 0);
    }

    void apply(int& u, int v, i64 l, i64 r, i64 p) {
        u = ++tot;
        ls.emplace_back(ls[v]);
        rs.emplace_back(rs[v]);
        sum.emplace_back(sum[v] + 1);
        if (l + 1 == r) {
            sum[u] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (p < mid) {
            apply(ls.back(), ls[v], l, mid, p);
            sum[u] = sum[ls[u]] + sum[rs[v]];
        } else {
            apply(rs.back(), rs[v], mid, r, p);
            sum[u] = sum[ls[v]] + sum[rs[u]];
        }
    }

    void apply(int v1, int v2, i64 p) {
        apply(root[v1], root[v2], 0, mxv, p);
    }

    int query(int l, int r) {
        debug(l, r, sum[root[r]], sum[root[l]]);
        return sum[root[r]] - sum[root[l]];
    }
};

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mxv = *max_element(a.begin(), a.end());
    ChairTree ct(n, mxv);
    for (int i = 0; i < n; i++) {
        ct.apply(i + 1, i, a[i]);
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        debug(l, r);
        cout << ct.query(l, r) << '\n';
    }
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