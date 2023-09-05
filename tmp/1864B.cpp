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
    if (k % 2 == 0) {
        sort(s.begin(), s.end());
        cout << s << '\n';
    } else {
        string s1, s2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                s1.push_back(s[i]);
            } else {
                s2.push_back(s[i]);
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) {
                s[i] = s1[i / 2];
            } else {
                s[i] = s2[i / 2];
            }
        }
        cout << s << '\n';
    }
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