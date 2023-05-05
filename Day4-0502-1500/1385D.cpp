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
    auto work = [&](auto&& self, int l, int r, char c) {
        if (r - l == 1) {
            if (s[l] == c)
                return 0;
            else
                return 1;
        }
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = l; i < mid; i++) {
            if (s[i] != c) cnt++;
        }
        int res = cnt + self(self, mid, r, c + 1);
        cnt = 0;
        for (int i = mid; i < r; i++) {
            if (s[i] != c) cnt++;
        }
        res = min(res, cnt + self(self, l, mid, c + 1));
        return res;
    };
    cout << work(work, 0, n, 'a') << '\n';
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