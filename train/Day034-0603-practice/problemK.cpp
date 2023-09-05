#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using std::cin;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    int cnt0 = 0;
    map<int, int> cnt;
    bool hasequal = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) cnt0++;
        cnt[x]++;
        if (cnt[x] == 2) {
            hasequal = true;
        }
    }
    if (cnt0)
        cout << n - cnt0 << endl;
    else if (hasequal)
        cout << n << endl;
    else
        cout << n + 1 << endl;
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