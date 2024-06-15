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
    vector<int> rs, ls, sum, root;

    ChairTree() {}

    ChairTree(int n_, int mxv_) {
        init(n_, mxv_);
    }

    void init(int n_, int mxv_) {
        n = n_;
        mxv = mxv_;
        tot = 0;
        rs.resize(1, 0);
        ls.resize(1, 0);
        sum.resize(1, 0);
        root.resize(n, 0);
    }

    void apply(int& u, int v, int l, int r, int p) {
        u = ++tot;
        rs.emplace_back();
        ls.emplace_back();
        sum.emplace_back();
        ls.back() = ls[v], rs.back() = rs[v], sum.back() = sum[v] + 1;
        if (l + 1 == r) return;
        int mid = (l + r) >> 1;
        if (p < mid)
            apply(ls.back(), ls[v], l, mid, p);
        else
            apply(rs.back(), rs[v], mid, r, p);
    }

    void apply(int v1, int v2, int p) {
        apply(root[v1], root[v2], 0, mxv, p);
    }

    int query(int u, int v, int l, int r, int k) {
        if (l + 1 == r) return 0;
        int sr = sum[rs[u]] - sum[rs[v]];
        int mid = (l + r) >> 1;
        if (k < mid)
            return query(ls[u], ls[v], l, mid, k) + sr;
        else
            return query(rs[u], rs[v], mid, r, k);
    }

    int query(int l, int r, int k) {
        return query(root[r], root[l], 0, mxv, k);
    }
};

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mxv = *max_element(a.begin(), a.end());
    ChairTree ct(n + 1, mxv);
    for (int i = 0; i < n; i++) {
        ct.apply(i + 1, i, a[i]);
    }
    cin >> m;
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        cout << ct.query(l, r, k) << '\n';
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