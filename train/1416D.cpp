#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return max(a, b);
}

struct DSU {
    vector<int> f, siz;

    DSU() {}

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
template <class Info>
struct SegmentTree {
    int n;
    vector<Info> info;

    SegmentTree() : n(0) {}

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template <class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }

    template <class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info& v) {
        modify(1, 0, n, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }

    template <class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }

    template <class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }

    template <class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    vector<int> u(m), v(m), t(m);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
        t[i] = q;
    }
    vector<int> type(q), x(q), node(q);
    for (int i = 0; i < q; ++i) {
        cin >> type[i] >> x[i];
        --x[i];
        if (type[i] == 2)
            t[x[i]] = i;
    }
    vector<int> lc(2 * n, -1), rc(2 * n, -1);
    int cur = n;
    DSU dsu(2 * n);
    for (int i = 0; i < m; ++i) {
        if (t[i] != q)
            continue;
        int a = dsu.find(u[i]), b = dsu.find(v[i]);
        if (a != b) {
            lc[cur] = a;
            rc[cur] = b;
            dsu.merge(cur, a);
            dsu.merge(cur, b);
            ++cur;
        }
    }
    for (int i = q - 1; i >= 0; --i) {
        if (type[i] == 1) {
            node[i] = dsu.find(x[i]);
        } else {
            int a = dsu.find(u[x[i]]), b = dsu.find(v[x[i]]);
            if (a != b) {
                lc[cur] = a;
                rc[cur] = b;
                dsu.merge(cur, a);
                dsu.merge(cur, b);
                ++cur;
            }
        }
    }
    int now = 0;
    vector<int> in(2 * n), out(2 * n), a(n);
    auto dfs = [&](auto dfs, int u) {
        in[u] = now;
        if (u < n) {
            a[now] = u;
            out[u] = ++now;
            return;
        }
        dfs(dfs, lc[u]);
        dfs(dfs, rc[u]);
        out[u] = now;
    };
    for (int i = 0; i < cur; ++i)
        if (dsu.find(i) == i)
            dfs(dfs, i);

    SegmentTree<pair<int, int>> tr(n);
    for (int i = 0; i < n; ++i)
        tr.modify(in[i], pair{p[i], in[i]});
    for (int i = 0; i < q; ++i) {
        if (type[i] == 2)
            continue;
        int s = tr.rangeQuery(in[node[i]], out[node[i]]).second;
        cout << p[a[s]] << "\n";
        p[a[s]] = 0;
        tr.modify(s, pair{0, s});
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