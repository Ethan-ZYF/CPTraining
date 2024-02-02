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
    cin >> n;
    vector<int> a(n), ans(n), st;
    for (auto& x : a)
        cin >> x;

    ans[n - 1] = -1;
    st.push_back(n - 1);
    auto cmp = [&](int i, int v) -> bool {
        return a[i] < v;
    };
    for (int i = n - 2; i >= 0; i--) {
        int v = a[i];
        int j = upper_bound(st.begin(), st.end(), v, cmp) - st.begin();
        if (j < st.size()) {
            ans[i] = st[j] - i - 1;
        } else {
            ans[i] = -1;
        }
        if (v < a[st.back()]) {
            st.push_back(i);
        }
        debug(st, v, j);
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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