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

struct Tag {
    i64 x;

    Tag(i64 _x = 0) : x{_x} {}

    void apply(const Tag &t) {
        x += t.x;
    }
};

struct Info {
    i64 x;
    int sz;

    Info(i64 _x = 0, int _sz = 1) : x{_x}, sz{_sz} {}

    void apply(const Tag &t) {
        x += t.x * sz;
    }
};

Info operator+(const Info &a, const Info &b) {
    return Info{a.x + b.x, a.sz + b.sz};
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64> a(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<i64> in(n), out(n);
    auto dfs = [&](auto &&self, int x, int p) -> void {
        static int tim = 0;
        in[x] = tim++;
        for (auto y : g[x]) {
            if (y != p) {
                self(self, y, x);
            }
        }
        out[x] = tim;
    };
    dfs(dfs, 0, -1);
    debug(a);
    LazySegmentTree<Info, Tag> st(n);
    for (int i = 0; i < n; i++) {
        st.modify(in[i], Info{a[i]});
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            int prev = a[s];
            st.rangeApply(in[s], in[s] + 1, Tag{x - prev});
            a[s] = x;
        } else {
            int s;
            cin >> s;
            s--;
            cout << st.rangeQuery(in[s], out[s]).x << '\n';
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