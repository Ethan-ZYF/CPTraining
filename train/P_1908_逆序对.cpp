#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class Info>
struct Seg {
    i64 left, right;
    Info info;
    Seg *left_child = nullptr, *right_child = nullptr;

    Seg(i64 lb, i64 rb) {
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
        info = Info();
        if (left_child) info = info + left_child->info;
        if (right_child) info = info + right_child->info;
    }

    void modify(i64 k, const Info& v) {
        if (left + 1 == right) {
            info = v;
            return;
        }
        i64 mid = (left + right) / 2;
        if (k < mid) {
            if (!left_child) left_child = new Seg(left, mid);
            left_child->modify(k, v);
        } else {
            if (!right_child) right_child = new Seg(mid, right);
            right_child->modify(k, v);
        }
        pull();
    }

    Info rangeQuery(i64 lq, i64 rq) {
        if (lq <= left && right <= rq)
            return info;
        if (max(left, lq) >= min(right, rq))
            return Info();
        Info ans;
        if (left_child)
            ans = ans + left_child->rangeQuery(lq, rq);
        if (right_child)
            ans = ans + right_child->rangeQuery(lq, rq);
        return ans;
    }
};

constexpr i64 INF = 1e9 + 5;

struct Info {
    i64 x;
    Info(i64 x = 0) : x(x) {}
};

Info operator+(const Info& a, const Info& b) {
    return Info(a.x + b.x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    map<int, int> mp;
    i64 ans = 0;
    Seg<Info> seg(0, INF);
    for (auto x : a) {
        i64 tmp = seg.rangeQuery(x + 1, INF).x;
        debug(mp);
        debug(tmp);
        ans += tmp;
        mp[x]++;
        seg.modify(x, Info(mp[x]));
        debug(ans);
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