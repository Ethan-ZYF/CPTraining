#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class Info, class Merge = std::plus<Info>>
struct Seg {
    const Merge merge;
    int left, right;
    Info info = 0;
    Seg *left_child = nullptr, *right_child = nullptr;

    Seg(int lb, int rb) : merge(Merge()), left(lb), right(rb) {}

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Seg(left, t);
            right_child = new Seg(t, right);
        }
    }

    void modify(int k, int x) {
        extend();
        info = merge(info, x);
        if (left_child) {
            if (k < left_child->right)
                left_child->modify(k, x);
            else
                right_child->modify(k, x);
        }
    }

    Info rangeQuery(int lq, int rq) {
        if (lq <= left && right <= rq)
            return info;
        if (std::max(left, lq) >= std::min(right, rq))
            return 0;
        extend();
        return merge(left_child->rangeQuery(lq, rq), right_child->rangeQuery(lq, rq));
    }

    vector<pair<int, Info>> getLeaves() {
        if (!left_child) {
            if (!info) return {};
            return {{left, info}};
        }
        auto l = left_child->getLeaves();
        auto r = right_child->getLeaves();
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};

constexpr int MXN = 1e9 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector grid(n, vector(m, 0));
    for (auto& row : grid) {
        for (auto& x : row) {
            cin >> x;
        }
    }
    Seg<int> segtree(0, MXN);
    i64 ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            i64 times = n - i - 1;
            i64 base = (j + 1) * times;
            i64 add = segtree.rangeQuery(0, grid[i][j]);
            ans += base + add;
        }
        for (int j = 0; j < m; j++)
            segtree.modify(grid[i][j], 1);
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