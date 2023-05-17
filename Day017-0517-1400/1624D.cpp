#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    array<int, 26> cnt{};
    for (auto& c : s) {
        cnt[c - 'a']++;
    }
    int even = 0, odd = 0;
    for (auto& x : cnt) {
        even += x / 2;
        odd += x % 2;
    }
    int ans = even / k * 2;
    int rest = even % k;
    rest *= 2;
    rest += odd;
    if(rest >= k) ans++;
    cout << min(ans, n) << '\n';
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