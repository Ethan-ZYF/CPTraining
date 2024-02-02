#include <bits/stdc++.h>
//https://www.luogu.com.cn/problem/P3372
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long
#define ull unsigned long long
#define lowbit(i) ((i) & (-i))
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 200;

int qpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

struct node {
    int val;
    int l, r;
    int add;
} tree[4 * N];
int a[N];

struct segm {
    int l;
    int r;
    int id;
} seg[N];

void pushup(int p) {
    tree[p].val = tree[ls(p)].val + tree[rs(p)].val;
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}

void pushdown(int p) {
    if (tree[p].add) {
        tree[ls(p)].val += (tree[ls(p)].r - tree[ls(p)].l + 1) * tree[p].add;
        tree[ls(p)].add += tree[p].add;
        tree[rs(p)].val += (tree[rs(p)].r - tree[rs(p)].l + 1) * tree[p].add;
        tree[rs(p)].add += tree[p].add;
        tree[p].add = 0;
    }
}

void update(int l, int r, int k, int p = 1) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].val += (tree[p].r - tree[p].l + 1) * k;
        tree[p].add += k;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        update(l, r, k, ls(p));
    if (r > mid)
        update(l, r, k, rs(p));
    pushup(p);
}

int query(int l, int r, int p = 1) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].val;
    }
    pushdown(p);
    int ans = 0;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        ans += query(l, r, ls(p));
    if (r > mid)
        ans += query(l, r, rs(p));
    return ans;
}

bool cmp1(const segm& a, const segm& b) {
    return a.l < b.l;
}

bool operator<(const segm& a, const segm& b) {
    return a.r > b.r;
}

signed main() {
    IOS int n, k;
    cin >> n >> k;
    build(1, 1, 200000);
    for (int i = 1; i <= n; i++) {
        seg[i].id = i;
        cin >> seg[i].l >> seg[i].r;
        update(seg[i].l, seg[i].r, 1);
    }
    sort(seg + 1, seg + n + 1, cmp1);
    multiset<segm> s;
    int index = 1;
    int ans = 0;
    vector<int> ans1;
    for (int i = 1; i <= 200000; i++) {
        while (index <= n && i == seg[index].l) {
            s.insert(seg[index]);
            index++;
        }
        while (query(i, i) > k) {
            auto [l, r, id] = *s.begin();
            update(l, r, -1);
            ans1.push_back(id);
            s.erase(s.begin());
            ans++;
        }
    }
    cout << ans << endl;
    for (auto i : ans1)
        cout << i << " ";
    return 0;
}