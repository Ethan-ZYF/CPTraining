#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int mex(vector<int>& a) {
    set<int> s(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (s.count(i) == 0) return i;
    }
    return a.size();
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;

    a.push_back(mex(a));
    n++;
    k %= n;
    rotate(a.rbegin(), a.rbegin() + k, a.rend());
    debug(a);
    a.pop_back();
    for (auto& ai : a) cout << ai << " ";
    cout << "\n";
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