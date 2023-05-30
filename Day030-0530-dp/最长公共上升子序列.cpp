#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

/*
longest common increasing subsequence
given two arrays a and b, find the longest common subsequence of a and b
such that the subsequence is increasing

dp[i][j] means the length of the longest common increasing subsequence
of a[1..i] and b[1..j] that ends with b[j]


*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector f(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int mxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            //* TLE
            // if (a[i] == b[j]) {
            // int mxv = 1;
            // for (int k = 1; k < j; k++) {
            //     if (b[k] < b[j]) mxv = max(mxv, f[i - 1][k] + 1);
            // }
            // f[i][j] = max(f[i][j], mxv);
            // }
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], mxv);
            }
            if (b[j] < a[i]) {
                mxv = max(f[i - 1][j] + 1, mxv);
            }
        }
    }
    cout << *max_element(f.back().begin(), f.back().end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}