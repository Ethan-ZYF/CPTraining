#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template <class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }

    template <class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
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

    void apply(int p, const Tag& v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag& v) {
        return rangeApply(1, 0, n, l, r, v);
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
        push(p);
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
        push(p);
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

struct Tag {
    i64 v;

    Tag(i64 v = 0) : v(v) {}

    void apply(Tag t) {
        v += t.v;
    }
};

struct Info {
    i64 x = 0;
    int sz = 1;

    Info(i64 x = 0, int sz = 1) : x(x), sz(sz) {}

    void apply(Tag t) {
        x += t.v * sz;
    }
};

Info operator+(Info a, Info b) {
    return {a.x + b.x, a.sz + b.sz};
}

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;

    HLD() {}

    HLD(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }

        siz[u] = 1;
        for (auto& v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }

    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }

        int d = dep[u] - k;

        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }

        return seq[in[u] - dep[u] + d];
    }

    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }

    int rootedChild(int u, int v) {
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) { return in[x] < in[y]; }) - 1;
        return *it;
    }

    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedChild(v, u)];
    }

    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }

    template <class F>
    void updatePath(int u, int v, const F& f) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]])
                std::swap(u, v);
            f(in[top[u]], in[u] + 1);
            u = parent[top[u]];
        }
        if (dep[u] > dep[v])
            std::swap(u, v);
        f(in[u], in[v] + 1);
    }

    template <class Info, class F>
    Info queryPath(int u, int v, const F& f) {
        Info res;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]])
                std::swap(u, v);
            res = res + f(in[top[u]], in[u] + 1);
            u = parent[top[u]];
        }
        if (dep[u] > dep[v])
            std::swap(u, v);
        res = res + f(in[u], in[v] + 1);
        return res;
    }
};

string to_string(Info x) {
    return to_string(x.x);
}

string to_string(Tag x) {
    return to_string(x.v);
}

string to_string(LazySegmentTree<Info, Tag> seg) {
    string res = "{";
    for (int i = 0; i < seg.n; i++) {
        res += to_string(seg.rangeQuery(i, i + 1));
        res += ",";
    }
    res.pop_back();
    res += "}";
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    HLD hld(n);
    vector<i64> a(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    hld.work();
    auto dfs = [&](auto self, int u, int p) -> i64 {
        i64 res = a[u];
        for (int v : g[u])
            if (v != p)
                res += self(self, v, u);
        return a[u] = res;
    };
    dfs(dfs, 0, -1);
    LazySegmentTree<Info, Tag> seg(n);
    int rt = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int cur;
            cin >> cur;
            cur--;
            rt = cur;
        } else if (op == 2) {
            int u, v, x;
            cin >> u >> v >> x;
            u--, v--;
            int lca = hld.lca(u, v);
            if (lca == rt) {
                seg.rangeApply(0, n, Tag(x));
            } else if (!hld.isAncester(lca, rt)) {
                seg.rangeApply(hld.in[lca], hld.out[lca], Tag(x));
            } else {
                int max_dep = max(hld.dep[hld.lca(rt, u)], hld.dep[hld.lca(rt, v)]);
                debug(max_dep);
                if (hld.dep[rt] > max_dep) {
                    debug(hld.dep[rt], max_dep);
                    int subV = hld.jump(rt, hld.dep[rt] - max_dep - 1);
                    seg.rangeApply(hld.in[subV], hld.out[subV], Tag(-x));
                }
                seg.rangeApply(0, n, Tag(x));
            }
        } else {
            int v;
            cin >> v;
            v--;
            if (v == rt) {
                cout << a[0] + seg.rangeQuery(0, n).x << '\n';
            } else if (!hld.isAncester(v, rt)) {
                i64 res = seg.rangeQuery(hld.in[v], hld.out[v]).x;
                res += a[v];
                cout << res << '\n';
            } else {
                int subV = hld.jump(rt, hld.dep[rt] - hld.dep[v] - 1);
                i64 res = seg.rangeQuery(0, n).x + a[0];
                res -= seg.rangeQuery(hld.in[subV], hld.out[subV]).x;
                res -= a[subV];
                cout << res << '\n';
            }
        }
        debug(seg);
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