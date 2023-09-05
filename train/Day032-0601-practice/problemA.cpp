#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

inline int f(char c) {
    return c - 'a';
}
inline char f(int c) {
    return c == -1 ? '*' : char('a' + c);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> next(26, -1), last(26, -1);
    auto get_path_end = [&](int c) -> pair<int, int> {
        int len = 0;
        int cur = c;
        while (next[cur] != -1)
            len++, cur = next[cur];
        return {cur, len};
    };

    for (auto c : s) {
        int cur = f(c);
        if (next[cur] == -1) {
            for (int i = 0; i < 26; i++) {
                if (last[i] == -1) {
                    auto [j, len] = get_path_end(i);
                    debug(f(i), f(j), len);
                    if (j != cur || len == 25) {
                        next[cur] = i;
                        last[i] = cur;
                        break;
                    }
                }
            }
        }
        cur = next[cur];
        cout << char('a' + cur);
    }
    cout << "\n";
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