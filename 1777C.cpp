#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int INF = 1e9;
constexpr int mx = 1e5 + 5;
vector<vector<int>> factors;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int l = 0, ans = INF;
    map<int, int> cnt;
    for (int r = 0; r < n; r++) {
        for (auto x : factors[a[r]]) {
            if (x > m)
                break;
            cnt[x]++;
        }
        while (cnt.size() >= m) {
            ans = min(ans, a[r] - a[l]);
            for (auto x : factors[a[l]]) {
                if (x > m)
                    break;
                if (cnt.contains(x))
                    cnt[x]--;
                if (cnt[x] == 0)
                    cnt.erase(x);
            }
            l++;
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    factors.resize(mx);
    for (int i = 1; i < mx; i++) {
        for (int j = i; j < mx; j += i) {
            factors[j].push_back(i);
        }
    }

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}