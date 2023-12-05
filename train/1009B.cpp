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
    array<vector<int>, 3> pos;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        pos[s[i] - '0'].push_back(i);
    }
    if (pos[2].empty()) {
        string ans = s;
        sort(ans.begin(), ans.end());
        cout << ans << '\n';
    } else {
        string ans;
        int up = pos[2][0];
        int i = 0;
        for (; i < pos[0].size() and pos[0][i] < up; ++i) {
            ans.push_back('0');
        }
        ans += string(pos[1].size(), '1');
        int j = 0;
        while (i < pos[0].size() and j < pos[2].size()) {
            if (pos[0][i] < pos[2][j]) {
                ans.push_back('0');
                ++i;
            } else {
                ans.push_back('2');
                ++j;
            }
        }
        while (i < pos[0].size()) {
            ans.push_back('0');
            ++i;
        }
        while (j < pos[2].size()) {
            ans.push_back('2');
            ++j;
        }
        cout << ans << '\n';
    }
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