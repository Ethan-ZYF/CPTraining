#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

inline int dceil(int x, int y) {
    return (x + y - 1) / y;
}

int cnt(string& s) {
    map<char, int> cnter;
    for (auto c : s) cnter[c]++;
    int mxv = ranges::max(cnter | views::values);
    return ssize(s) - mxv;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int hf = dceil(k, 2);
    vector<string> a(hf);
    // 0 k - 1
    vector<int> tmp(n);
    for (int i = 0; i < hf; i++) {
        for (int j = 0; j < n / k; j++) {
            int i1 = i + j * k;
            int i2 = k - i - 1 + j * k;
            if (i1 == i2) {
                a[i] += s[i1];
                continue;
            }
            a[i] += s[i1];
            a[i] += s[i2];
        }
    }
    int ans = 0;
    for (auto& s : a) {
        ans += cnt(s);
    }
    cout << ans << '\n';
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