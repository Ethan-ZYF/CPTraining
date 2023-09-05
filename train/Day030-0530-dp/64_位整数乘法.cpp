#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

std::istream &operator>>(std::istream &is, i128 &n) {
    std::string s;
    is >> s;
    n = 0;
    for (char c : s)
        n = n * 10 + c - '0';
    return is;
}

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    i128 a, b, p;
    cin >> a >> b >> p;
    cout << a * b % p << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}