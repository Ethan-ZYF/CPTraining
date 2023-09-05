#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

int f[101][101][2][2];

int rec(int c0, int c1, int x, int p) {
    // even 剩的， odd 剩的，alice的总和，当前是谁的回合
    if (f[c0][c1][x][p] != -1) {
        return f[c0][c1][x][p];
    }
    int& res = f[c0][c1][x][p];
    res = 0;
    if (!c0 && !c1) {
        //* x, p
        //* 0, 0 => win
        //* 0, 1 => lose
        //* 1, 0 => lose
        //? 1, 1 => win
        res = !x ^ p;
    } else {
        if (c0) {
            res |= !rec(c0 - 1, c1, x, !p);
        }
        if (c1) {
            res |= !rec(c0, c1 - 1, x ^ !p, !p);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0, even = 0;
    for (auto& x : a) {
        cin >> x;
        x &= 1;
        if (x == 1)
            odd++;
        else
            even++;
    }
    // even = even & 1;
    // odd = odd & 3;
    // if (even) {
    //     // 1 even
    //     //     0 odd => alice
    //     //     1 odd => alice
    //     //     2 odd => bob: alice odd, even if bob take odd
    //     //     3 odd => alice: alice got two odd, even if bob take odd
    //     if (odd == 2)
    //         cout << "Bob";
    //     else
    //         cout << "Alice";
    //     cout << endl;
    // } else {
    //     // not enough odd for alice to make even
    //     if (odd == 3 or odd == 0)
    //         cout << "Alice";
    //     else
    //         cout << "Bob";
    // }
    // cout << endl;
    std::cout << (rec(even, odd, 0, 0) ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::memset(f, -1, sizeof(f));
    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}