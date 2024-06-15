#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
struct ChairTree {
    struct Node;
    using iter = std::vector<Node>::iterator;

    struct Node {
        int sum;
        iter ls;
        iter rs;

        Node(int sum = 0, iter ls = nullptr, iter rs = nullptr) : sum(sum), ls(ls), rs(rs) {}
    };

    int tot, n, L, R;
    std::vector<Node> root;

    ChairTree() : tot(0), n(0), L(0), R(1e9 + 1) {}

    ChairTree(int n_, int L = 0, int R = 1e9 + 1) : tot(0), n(n_), L(L), R(R) {
        root.resize(n, nullptr);
    }

    void apply(Node*& u, Node* v, int l, int r, int p) {
        u = new Node(v ? v->sum + 1 : 1, v ? v->ls : nullptr, v ? v->rs : nullptr);
        if (l + 1 == r) return;
        int mid = (l + r) >> 1;
        if (p < mid)
            apply(u->ls, v ? v->ls : nullptr, l, mid, p);
        else
            apply(u->rs, v ? v->rs : nullptr, mid, r, p);
    }

    void apply(int v1, int v2, int p) {
        apply(root[v1], root[v2], L, R, p);
    }

    int query(Node* u, Node* v, int l, int r, int k) {
        if (l + 1 == r) return l;
        int sl = (u && u->ls ? u->ls->sum : 0) - (v && v->ls ? v->ls->sum : 0);
        int mid = (l + r) >> 1;
        if (sl >= k)
            return query(u ? u->ls : nullptr, v ? v->ls : nullptr, l, mid, k);
        else
            return query(u ? u->rs : nullptr, v ? v->rs : nullptr, mid, r, k - sl);
    }

    int query(int l, int r, int k) {
        return query(root[r], root[l], L, R, k);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    ChairTree ct(n, -1e9, 1e9 + 1);
    for (int i = 0; i < n; i++) {
        ct.apply(i + 1, i, a[i]);
    }
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