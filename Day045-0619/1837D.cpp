#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n), ps(n + 1);
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == '(' ? 1 : -1);
    partial_sum(a.begin(), a.end(), ps.begin() + 1);
    debug(a);
    debug(ps);
    if (ps.back() != 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (flag) {
            if (ps[i + 1] >= 0) {
                ans[i] = 1;
            } else {
                ans[i] = 2;
                flag = false;
            }
        } else {
            if (ps[i + 1] <= 0) {
                ans[i] = 2;
            } else {
                ans[i] = 1;
                flag = true;
            }
        }
    }
    set<int> st(ans.begin(), ans.end());
    cout << st.size() << '\n';
    if (st.size() == 1) {
        for (int i = 0; i < n; i++)
            cout << 1 << " \n"[i == n - 1];
        return;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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