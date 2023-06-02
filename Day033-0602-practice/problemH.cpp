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

    map<char, char> mp;
    for (auto c : s) {
        while (k and c != 'a' and mp.find(c) == mp.end()) {
            mp[c] = c - 1;
            c--;
            k--;
        }
    }
    for (char& c : s) {
        while (mp.find(c) != mp.end() and mp[c] != c) c = mp[c];
    }
    cout << s << endl;
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