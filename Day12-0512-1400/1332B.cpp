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
    for (auto& x : a) cin >> x;
    set<int> s;
    for (auto& x : a) {
        int base = 2;
        while (x % base != 0) base++;
        x = base;
        s.insert(base);
    }
    vector<int> p(s.begin(), s.end());
    debug(p);
    debug(a);
    cout << p.size() << '\n';
    for(auto x : a){
        int pos = lower_bound(p.begin(), p.end(), x) - p.begin();
        cout << pos + 1 << ' ';
    }
    cout << '\n';
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