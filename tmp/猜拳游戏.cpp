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
    for_each(s.begin(), s.end(), [](char& c) { c = tolower(c); });
    vector<string> vs = {"shitou", "jiandao", "bu"};
    int i = find(vs.begin(), vs.end(), s) - vs.begin();
    i++;
    if (i == 3) {
        i = 0;
    }
    cout << vs[i] << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}