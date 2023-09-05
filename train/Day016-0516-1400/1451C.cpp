#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int i, n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    array<int, 27> have{}, need{};
    for (auto& c : a)
        have[c - 'a']++;
    for (auto& c : b)
        need[c - 'a']++;

    bool bad = false;
    for (i = 0; i < 26; i++) {
        if (have[i] < need[i] || (have[i] -= need[i]) % k)
            bad = true;
        have[i + 1] += have[i];
    }
    cout << (bad ? "No" : "Yes") << '\n';
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