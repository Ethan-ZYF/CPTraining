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
    vector<int> child(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        child[x]++;
    }

    sort(child.begin(), child.end(), greater());
    while (child.back() == 0) child.pop_back();
    child.push_back(1);
    int m = child.size();
    auto check = [&](int x) -> bool {
        if(x < m) return false;
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum++;
            sum += max(0, child[i] - (x - i));
        }
        return sum <= x;
    };
    int lo = m - 1, hi = n + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
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