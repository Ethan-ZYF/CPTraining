#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool goods = true, goodt = true;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            goods = false;
            break;
        }
    }
    for (int i = 1; i < m; i++) {
        if (t[i] == t[i - 1]) {
            goodt = false;
            break;
        }
    }

    if (!goods && !goodt) {
        cout << "No\n";
        return;
    }
    if (goods) {
        cout << "Yes\n";
        return;
    }
    if(t[0] != t.back()) {
        cout << "No\n";
        return;
    }
    debug(s, t);
    char c = t[0];
    for (int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            if(s[i] == c){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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