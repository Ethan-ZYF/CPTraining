#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 2e5 + 5;

int n, q, a[MN];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        int tot = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            tot += a[i];
        }
        set<int> ones = {};
        for (int i = 1; i <= n; ++i)
            if (a[i] == 1)
                ones.insert(i);
        for (int i = 1, op, s, pos, v; i <= q; ++i) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &s);
                int val = 0;
                if ((s & 1) == (tot & 1))
                    printf("%s\n", s <= tot ? "YES" : "NO");
                else {
                    if (ones.empty())
                        printf("NO\n");
                    else {
                        int max_val = tot - min(*ones.begin() * 2 - 1,
                                                (n - *ones.rbegin()) + 1);
                        printf("%s\n", s <= max_val ? "YES" : "NO");
                    }
                }
            } else {
                scanf("%d%d", &pos, &v);
                if (a[pos] == 1)
                    ones.erase(pos);
                tot += v - a[pos];
                a[pos] = v;
                if (a[pos] == 1)
                    ones.insert(pos);
            }
        }
    }
    return 0;
}