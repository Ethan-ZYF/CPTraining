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
    string s;
    cin >> s;
    vector<string> pattern = {"aa", "aba", "aca", "abca", "acba", "accabba", "abbacca"};
    for (auto& p : pattern) {
        if (s.find(p) != string::npos) {
            cout << ssize(p) << endl;
            return;
        }
    }
    cout << -1 << endl;
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