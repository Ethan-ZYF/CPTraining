#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

bool cmp(pair<int, int> a, pair<int, int> b) {
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena != lenb) return lena > lenb;
    return a.first < b.first;
}
void solve() {
    int n;
    cin >> n;
    set<pair<int, int>, decltype(cmp)*> s(cmp);
    s.insert({0, n});
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        auto it = s.begin();
        auto [l, r] = *it;
        s.erase(it);
        int mid = (l + r - 1) / 2;
        ans[mid] = i;
        if (mid > l) s.insert({l, mid});
        if (mid + 1 < r) s.insert({mid + 1, r});
        debug(s);
    }
    for (auto& x : ans) cout << x << " \n"[&x == &ans.back()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}