#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> s0(n + 1), s1(n + 1);
    for (int i = 0; i < n; i++) {
        s0[i + 1] = s0[i] + (s[i] == '0');
        s1[i + 1] = s1[i] + (s[i] == '1');
    }
    int tot1 = s1[n];
    auto check = [&](int x) -> bool {
        int l = 0;
        for (int r = 0; r <= n; r++){
            while (s0[r] - s0[l] > x) {
                l++;
            }
            int left1 = tot1 - (s1[r] - s1[l]);
            if (left1 <= x) {
                return true;
            }
        }
        return false;
    };
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
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