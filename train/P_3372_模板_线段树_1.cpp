#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class Info, class Tag>
struct Seg {
    int left, right;
    Info info;
    Tag tag;
    Seg *left_child = nullptr, *right_child = nullptr;

    Seg(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void apply(const Tag& v) {
        info.sz = right - left;
        info.apply(v);
        tag.apply(v);
    }

    void push() {
        if (left_child) {
            left_child->apply(tag);
            right_child->apply(tag);
        }
        tag = Tag();
    }

    void pull() {
        info = left_child->info + right_child->info;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Seg(left, t);
            right_child = new Seg(t, right);
        }
    }

    void modify(int k, const Info& v) {
        if (left + 1 == right) {
            info = v;
            return;
        }
        extend();
        push();
        if (k < left_child->right) {
            left_child->modify(k, v);
        } else {
            right_child->modify(k, v);
        }
        pull();
    }

    Info rangeQuery(int l, int r) {
        if (l >= right || r <= left) {
            return Info();
        }
        if (l <= left && r >= right) {
            return info;
        }
        extend();
        push();
        return left_child->rangeQuery(l, r) + right_child->rangeQuery(l, r);
    }

    void rangeApply(int l, int r, const Tag& v) {
        if (l >= right || r <= left) {
            return;
        }
        if (l <= left && r >= right) {
            apply(v);
            return;
        }
        extend();
        push();
        left_child->rangeApply(l, r, v);
        right_child->rangeApply(l, r, v);
        pull();
    }

    Info query(int k) {
        return rangeQuery(k, k + 1);
    }

    Info allQuery() {
        return rangeQuery(left, right);
    }
};

struct Tag {
    i64 sum;

    Tag(i64 v = 0) : sum(v) {}

    void apply(const Tag& v) {
        sum += v.sum;
    }
};

struct Info {
    i64 sum;
    int sz;
    Info(i64 v = 0, int sz = 1) : sum(v), sz(sz) {}

    void apply(const Tag& v) {
        sum += 1LL * v.sum * sz;
    }
};

Info operator+(const Info& a, const Info& b) {
    return Info(a.sum + b.sum, a.sz + b.sz);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    Seg<Info, Tag> seg(0, n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, Info(a[i]));
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.rangeApply(l - 1, r, Tag(x));
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.rangeQuery(l - 1, r).sum << "\n";
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