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
    array<int, 26> cnt{};
    for (char c : s)
        cnt[c - 'a']++;
    if ((n % 2 == 1) or *max_element(cnt.begin(), cnt.end()) > n / 2) {
        cout << -1 << endl;
        return;
    }
    cnt = {};
    int tot = 0;
    for (int i = 0; i < n / 2; i++) {
        int j = n - i - 1;
        if (s[i] == s[j]) {
            tot++;
            cnt[s[i] - 'a']++;
        }
    }
    int ans1 = *max_element(cnt.begin(), cnt.end());
    int ans2 = (tot + 1) / 2;
    cout << max(ans1, ans2) << endl;
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