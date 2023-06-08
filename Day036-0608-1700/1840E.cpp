#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    string S[2];
    cin >> S[0] >> S[1];
    int n = S[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (S[0][i] != S[1][i]) cnt++;
    }
    int t, Q;
    cin >> t >> Q;
    vector<vector<int>> ts(Q + t);
    for (int q = 0; q < Q; q++) {
        int op;
        cin >> op;
        for (int i : ts[q]) {
            // 过期了的
            if (S[0][i] != S[1][i]) cnt++;
        }
        if (op == 1) {
            int pos;
            cin >> pos;
            pos--;
            if (S[0][pos] != S[1][pos]) {
                cnt--;
                ts[q + t].push_back(pos);
            }
        } else if (op == 2) {
            int i, posi, j, posj;
            cin >> i >> posi >> j >> posj;
            i--, j--, posi--, posj--;
            int c1 = 0, c2 = 0;
            if (S[i][posi] != S[1 - i][posi]) c1++;
            if (S[j][posj] != S[1 - j][posj]) c1++;
            swap(S[i][posi], S[j][posj]);
            if (S[i][posi] != S[1 - i][posi]) c2++;
            if (S[j][posj] != S[1 - j][posj]) c2++;
            cnt += c2 - c1;
        } else {
            cout << (cnt <= 0 ? "YES" : "NO") << endl;
        }
    }
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