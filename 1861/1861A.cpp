#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

vector<pair<i64, int>> factor(i64 n) {
    vector<pair<i64, int>> res;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i, 0);
            while (n % i == 0) {
                res.back().second++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        res.emplace_back(n, 1);
    }
    return res;
}

struct Sieve {
    int n;
    std::vector<int> f, primes;
    Sieve(int n = 1) : n(n), f(n + 1) {
        f[0] = f[1] = -1;
        for (long long i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (long long j = i * i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool is_prime(int x) {
        return f[x] == x;
    }
} sieve(100);

bool is_subsequence(string& s, string& t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n and j < m) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else
            i++;
    }
    return j == m;
}

void solve() {
    vector<string> p;
    string s;
    cin >> s;
    for (int i = 10; i < 100; i++) {
        if (sieve.is_prime(i)) {
            p.push_back(to_string(i));
        }
    }

    for (auto& pi : p) {
        if (is_subsequence(s, pi)) {
            cout << pi << endl;
            return;
        }
    }
    cout << -1 << endl;
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