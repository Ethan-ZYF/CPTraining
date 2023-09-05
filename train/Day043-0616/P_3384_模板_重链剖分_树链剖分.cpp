#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
int P;

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
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
        for (auto &v : adj[u]) {
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
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
                      return in[x] < in[y];
                  }) -
                  1;
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
};

/*
 * @author jiangly
 * https://codeforces.com/profile/jiangly
 */
template <class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
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
    void modify(int p, const Info &v) {
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
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
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
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }

    int search(int p, int l, int r, int x, int y, i64 v) {
        if (l >= y || r <= x) return y;
        if (info[p].min >= v) return y;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        push(p);
        int res = search(2 * p, l, m, x, y, v);
        if (res == y) res = search(2 * p + 1, m, r, x, y, v);
        return res;
    }

    int search(int l, int r, i64 v) {
        return search(1, 0, n, l, r, v);
    }
};

constexpr i64 inf = 1E18;

struct Tag {
    i64 x;
    Tag(i64 _x = 0) : x{_x} {}

    void apply(const Tag &t) {
        x += t.x;
        x %= P;
    }
};

struct Info {
    i64 x;
    int sz;

    Info(i64 _x = 0, int _sz = 1) : x{_x}, sz{_sz} {}

    void apply(const Tag &t) {
        x += t.x * sz;
        x %= P;
    }
};

Info operator+(const Info &a, const Info &b) {
    return Info{(a.x + b.x) % P, a.sz + b.sz};
}

void solve() {
    int n, m, r, p;
    cin >> n >> m >> r >> p;
    P = p;
    HLD hld(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= P;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        hld.addEdge(x - 1, y - 1);
    }
    hld.work(r - 1);
    debug(hld.in);
    debug(hld.out);
    LazySegmentTree<Info, Tag> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(hld.in[i], Info{a[i]});
    }
    auto update_path = [&](int x, int y, i64 v) {
        while (hld.top[x] != hld.top[y]) {
            if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                swap(x, y);
            }
            seg.rangeApply(hld.in[hld.top[x]], hld.in[x] + 1, v);
            x = hld.parent[hld.top[x]];
        }
        if (hld.dep[x] > hld.dep[y]) {
            swap(x, y);
        }
        seg.rangeApply(hld.in[x], hld.in[y] + 1, v);
    };

    auto query_path = [&](int x, int y) {
        Info res;
        while (hld.top[x] != hld.top[y]) {
            if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                swap(x, y);
            }
            res = res + seg.rangeQuery(hld.in[hld.top[x]], hld.in[x] + 1);
            x = hld.parent[hld.top[x]];
        }
        if (hld.dep[x] > hld.dep[y]) {
            swap(x, y);
        }
        res = res + seg.rangeQuery(hld.in[x], hld.in[y] + 1);
        return res;
    };

    auto update_subtree = [&](int x, i64 v) {
        seg.rangeApply(hld.in[x], hld.out[x], v);
    };

    auto query_subtree = [&](int x) {
        debug(x, hld.in[x], hld.out[x]);
        return seg.rangeQuery(hld.in[x], hld.out[x]);
    };

    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                int x, y, z;
                cin >> x >> y >> z;
                x--, y--;
                z %= P;
                update_path(x, y, z);
                break;
            }
            case 2: {
                int x, y;
                cin >> x >> y;
                x--, y--;
                cout << query_path(x, y).x << '\n';
                break;
            }
            case 3: {
                int x, z;
                cin >> x >> z;
                x--;
                z %= P;
                update_subtree(x, z);
                break;
            }
            case 4: {
                int x;
                cin >> x;
                x--;
                cout << query_subtree(x).x << '\n';
                break;
            }
        }
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