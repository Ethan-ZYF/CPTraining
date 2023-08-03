#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int N;
    cin >> N;
    vector<int> value(N + 1, 0), prefix(N + 1, 0);
    vector<int> parent(N + 1, -1);
    vector<int> min_pref(N + 1, 0), max_pref(N + 1, 0);
    vector<int> min_sub(N + 1, 0), max_sub(N + 1, 0);
    int T = 1;
    value[0] = prefix[0] = max_pref[0] = max_sub[0] = 1;

    for (int q = 0; q < N; q++) {
        char type;
        cin >> type;

        if (type == '+') {
            int v, x;
            cin >> v >> x;
            v--;

            parent[T] = v;
            value[T] = x;
            prefix[T] = prefix[v] + x;

            min_pref[T] = min(min_pref[v], prefix[T]);
            max_pref[T] = max(max_pref[v], prefix[T]);

            min_sub[T] = min(min_sub[v], prefix[T] - max_pref[T]);
            max_sub[T] = max(max_sub[v], prefix[T] - min_pref[T]);

            T++;
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            u--;
            v--;
            assert(u == 0);
            cout << (min_sub[v] <= k && k <= max_sub[v] ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}