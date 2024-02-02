#include <bits/stdc++.h>

#define int long long
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

struct Tag {  //tag对tag的影响
    int x = 0;
    void apply(const Tag t) {
        x ^= t.x;
    }
};
struct Info {  //tag对info(端点值)的影响
    int sz = 1;
    std::array<int, 30> pos{};
    void apply(const Tag t) {
        for (int i = 0; i < 30; ++i) {
            if ((t.x >> i) & 1) {
                pos[i] = sz - pos[i];
            }
        }
    }
};
Info operator+(Info a, Info b) {  //加法，用于线段树的构成
    std::array<int, 30> temp{};
    for (int i = 0; i < 30; i++) {
        temp[i] = a.pos[i] + b.pos[i];
    }
    return Info{a.sz + b.sz, temp};
}

void Fuck() {
    int n;
    std::cin >> n;

    std::vector<Info> init(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        std::array<int, 30> a = {};
        for (int j = 0; j < 30; ++j) {
            a[j] = x % 2;
            x /= 2;
        }
        init[i].pos = a;
        init[i].sz = 1;
    }

    LazySegmentTree<Info, Tag> seg(init);

    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r;
            std::cin >> l >> r;
            auto s = seg.rangeQuery(l - 1, r).pos;
            long long ans = 0, base = 1;
            for(int i = 0; i < 30; i++){
                ans += base * s[i];
                base *= 2;
            }
            std::cout << ans << '\n';
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            seg.rangeApply(l - 1, r, {x});
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    while (_--) {
        Fuck();
    }

    return 0;
}