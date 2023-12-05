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
    int n = s.size();
    vector<int> state;
    //* state[i] : 数组长度为i时：0 无序 1 有序 2 都有可能
    //* 0 无序
    //* 1 有序
    //* 2 都有可能
    state.push_back(1);  // len == 0 => 有序
    int last1 = 0, last0 = n + 1;
    int len = 0;
    int cur;
    for (auto c : s) {
        switch (c) {
            case '+':
                len++;
                cur = state.back();
                if (len <= 1)
                    cur = 1;
                else if (cur == 0)
                    cur = 0;
                else
                    cur = 2;
                state.push_back(cur);
                break;
            case '-':
                len--;
                if (len <= last0) {
                    last0 = n + 1;
                }
                if (len <= last1) {
                    last1 = min(last1, len);
                }
                state.pop_back();
                break;
            case '1':
                if (state.back() == 0) {
                    cout << "NO\n";
                    return;
                }
                state.back() = 1;
                last1 = len;
                break;
            case '0':
                if (len <= last1) {
                    cout << "NO\n";
                    return;
                }
                if (state.back() == 1) {
                    cout << "NO\n";
                    return;
                }
                state.back() = 0;
                last0 = len;
                break;
        }
        if (len <= 1) {
            last1 = len;
            last0 = -1;
        }
    }
    cout << "YES\n";
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