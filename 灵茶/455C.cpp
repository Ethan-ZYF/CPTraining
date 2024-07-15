#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
namespace rgs = std::ranges;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct DSU {
    std::vector<int> f, siz;

    DSU() {}

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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

// 究极快读
namespace fastread {
const unsigned int S = 1 << 15;
char B[S + 3], *H, *T;

inline unsigned int gc() {
    if (H == T) T = (H = B) + fread(B, 1, S, stdin);
    return (H == T) ? EOF : *H++;
}

inline int read() {
    int sgn = 1;
    unsigned int x, ch;
    while ((ch = gc()) < 48) {
        if (ch == '-') sgn = -1;
    }
    x = ch ^ '0';
    while ((ch = gc()) > 47)
        x = x * 10 + (ch ^ '0');
    return x;
}

inline string readString() {
    string s;
    unsigned int ch;
    while ((ch = gc()) < 33)
        ;
    s.push_back(ch);
    while ((ch = gc()) > 32)
        s.push_back(ch);
    return s;
}
}  // namespace fastread

using fastread::read;

// 究极快写
namespace fastwrite {
const unsigned int S = 1 << 15;
unsigned int cnt;
char B[S + 3];

inline void write(unsigned int x) {
    if (x > 9) write(x / 10);
    B[cnt++] = (x % 10) | 48;
    if (cnt == S) {
        fwrite(B, 1, S, stdout);
        cnt = 0;
    }
}

inline void space() {
    B[cnt++] = 32;
    if (cnt == S) {
        fwrite(B, 1, S, stdout);
        cnt = 0;
    }
}

inline void endl() {
    B[cnt++] = 10;
    if (cnt == S) {
        fwrite(B, 1, S, stdout);
        cnt = 0;
    }
}

inline void show() {
    fwrite(B, 1, cnt, stdout);
    cnt = 0;
}
}  // namespace fastwrite

using fastwrite::write, fastwrite::space, fastwrite::show;
constexpr int N = 3e5 + 5;

void solve() {
    int n, m, q;
    n = read(), m = read(), q = read();
    vector<queue<int>> que(n + 1);
    array<int, N> deg{}, mix{}, diameter{};
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        u = read(), v = read();
        deg[u]++, deg[v]++;
        mix[u] ^= v, mix[v] ^= u;
        dsu.merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            que[dsu.find(i)].push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if(que[i].empty()) continue;
        int d = 0;
        while (que[i].size() > 1) {
            int sz = que[i].size();
            for (int j = 0; j < sz; j++) {
                int u = que[i].front();
                que[i].pop();
                int v = mix[u];
                mix[v] ^= u;
                deg[v]--;
                if (deg[v] == 1) que[i].push(v);
            }
            d++;
        }
        debug(d, que[i]);
        diameter[i] = (d << 1) - (que[i].size() ^ 1);
    }

    while (q--) {
        int t;
        t = read();
        if (t == 1) {
            int x;
            x = read();
            write(diameter[dsu.find(x)]);
            fastwrite::endl();
        } else {
            int x, y;
            x = read(), y = read();
            if (dsu.same(x, y)) continue;
            int u = dsu.find(x), v = dsu.find(y);
            int len1 = diameter[u], len2 = diameter[v];
            int len = max({len1, len2, (len1 + 1) / 2 + (len2 + 1) / 2 + 1});
            dsu.merge(u, v);
            diameter[dsu.find(u)] = len;
        }
    }
    show();
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