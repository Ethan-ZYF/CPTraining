#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

bool is_palindrome(int x) {
    string s = to_string(x);
    string t(s.rbegin(), s.rend());
    return s == t;
}
vector<int> dp(40001);

void solve() {
    vector<int> palin;
    for (int i = 1; i < 40000; i++) {
        if (is_palindrome(i)) {
            palin.push_back(i);
        }
    }
    dp[0] = 1;
    for (int x : palin) {
        for (int i = x; i <= 40001; i++) {
            dp[i] += dp[i - x];
            dp[i] %= 1000000007;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    solve();
    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}