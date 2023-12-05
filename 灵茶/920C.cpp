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
    vector<int> a(n);
    for (auto& it : a)
        cin >> it;
    string s;
    cin >> s;
    s.push_back('0');
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = s[i] - '0';

    for (int i = 0; i < n; i++) {
        if (b[i] == 0)
            continue;
        int begin = i;
        while (i < n && b[i] == 1) {
            i++;
        }
        sort(a.begin() + begin, a.begin() + i + 1);
    }
    bool ok = is_sorted(a.begin(), a.end());
    cout << (ok ? "YES" : "NO") << '\n';
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