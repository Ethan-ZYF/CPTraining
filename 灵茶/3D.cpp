#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int main() {
    string s;
    cin >> s;
    int n = s.size(), cnt = 0;
    priority_queue<pair<int, int>> h;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        switch (s[i]) {
            case '(':
                ++cnt;
                break;
            case ')':
                --cnt;
                break;
            case '?':
                s[i] = ')';
                --cnt;
                cin >> a >> b;
                h.emplace(b - a, i);
                ans += b;
                break;
        }
        if (cnt < 0) {
            if (h.empty()) {
                cout << "-1\n";
                return 0;
            }
            auto [diff, j] = h.top();
            h.pop();
            ans = ans - diff;
            s[j] = '(';
            cnt = cnt + 2;
        }
    }
    if (cnt != 0) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    cout << s;
    return 0;
}