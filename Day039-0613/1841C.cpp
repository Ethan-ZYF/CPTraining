#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr int val[5] = {1, 10, 100, 1000, 10000};

void solve() {
    string s;
    cin >> s;
    for (char &c : s) c -= 'A';
    reverse(s.begin(), s.end());
    int an = -2e9;
    auto check = [&](int p) {
        if (p == -1) return;
        for (char v : {0, 1, 2, 3, 4}) {
            swap(v, s[p]);
            char lt = 0;
            int now = 0;
            for (char c : s) {
                if (c >= lt) {
                    now += val[c];
                } else {
                    now -= val[c];
                }
                lt = max(lt, c);
            }
            an = max(an, now);
            swap(v, s[p]);
        }
    };
    for (int i : {0, 1, 2, 3, 4}) {
        check(s.find_first_of(i));
        check(s.find_last_of(i));
    }
    cout << an << '\n';
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