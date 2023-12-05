#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e7 + 7;

template <class Info>
struct Seg {
    int left, right;
    Info info;
    Seg *left_child = nullptr, *right_child = nullptr;

    Seg(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Seg(left, t);
            right_child = new Seg(t, right);
        }
    }

    void pull() {
        info = left_child->info + right_child->info;
    }

    void modify(int k, const Info& v) {
        if (left + 1 == right) {
            info = v;
            return;
        }
        extend();
        if (k < left_child->right) {
            left_child->modify(k, v);
        } else {
            right_child->modify(k, v);
        }
        pull();
    }

    Info rangeQuery(int lq, int rq) {
        if (lq <= left && right <= rq)
            return info;
        if (std::max(left, lq) >= std::min(right, rq))
            return 0;
        extend();
        return left_child->rangeQuery(lq, rq) + right_child->rangeQuery(lq, rq);
    }

    int ask_rank(int lq, int rq, int k) {
        if (left + 1 == right) {
            return left;
        }
        int lcnt = left_child->rangeQuery(lq, rq).sum;
        extend();
        if (k <= lcnt) {
            return left_child->ask_rank(lq, rq, k);
        } else {
            return right_child->ask_rank(lq, rq, k - lcnt);
        }
    }

    int ask_rank(int k) {
        return ask_rank(-INF, INF, k);
    }

    int ask_kth(int lq, int rq, int k) {
        if (left + 1 == right) {
            return left;
        }
        int lcnt = left_child->rangeQuery(lq, rq).sum;
        extend();
        if (k <= left_child->rangeQuery(lq, rq).sum) {
            return left_child->ask_kth(lq, rq, k);
        } else {
            return right_child->ask_kth(lq, rq, k - lcnt);
        }
    }

    int ask_kth(int k) {
        return ask_kth(-INF, INF, k);
    }

    int get_prev(int x) {
        return ask_kth(ask_rank(x) - 1);
    }

    int get_next(int x) {
        return ask_kth(ask_rank(x) + 1);
    }
};

struct Info {
    int sum;
    Info(int x = 0) : sum(x) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(lhs.sum + rhs.sum);
}

void solve() {
    int q;
    cin >> q;
    Seg<Info> seg(-INF, INF);
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                int x;
                cin >> x;
                int cur = seg.rangeQuery(x, x + 1).sum;
                seg.modify(x, Info(cur + 1));
                break;
            }
            case 2: {
                int x;
                cin >> x;
                int cur = seg.rangeQuery(x, x + 1).sum;
                if (cur > 0) {
                    seg.modify(x, Info(cur - 1));
                }
                break;
            }
            case 3: {
                int k;
                cin >> k;
                cout << seg.ask_rank(k) << "\n";
                break;
            }
            case 4: {
                int k;
                cin >> k;
                cout << seg.ask_kth(k) << "\n";
                break;
            }
            case 5: {
                int x;
                cin >> x;
                cout << seg.get_prev(x) << "\n";
                break;
            }
            case 6: {
                int x;
                cin >> x;
                cout << seg.get_next(x) << "\n";
                break;
            }
        }
        debug(op);
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