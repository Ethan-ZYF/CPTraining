#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, std::less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        int op, x;
        cin >> op >> x;
        switch (op) {
            case 1: {
                s.insert({x, i});
                break;
            }
            case 2: {
                s.erase(s.lower_bound({x, 0}));
                break;
            }
            case 3: {
                cout << s.order_of_key({x, 0}) + 1 << '\n';
                break;
            }
            case 4: {
                cout << s.find_by_order(x - 1)->first << '\n';
                break;
            }
            case 5: {
                cout << (--s.lower_bound({x, 0}))->first << '\n';
                break;
            }
            case 6: {
                cout << s.lower_bound({x + 1, 0})->first << '\n';
                break;
            }
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