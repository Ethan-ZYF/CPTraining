#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

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
    std::vector<int> factorList(int x) {
        std::vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    std::vector<std::pair<int, int>> factor(int x) {
        std::vector<int> fl = factorList(x);
        if (fl.size() == 0) return {};
        std::vector<std::pair<int, int>> res(1, std::pair<int, int>(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p)
                ++res.back().second;
            else
                res.emplace_back(p, 1);
        }
        return res;
    }
    std::vector<std::pair<long long, int>> factor(long long x) {
        std::vector<std::pair<long long, int>> res;
        for (int p : primes) {
            int y = 0;
            while (x % p == 0) {
                ++y;
                x /= p;
            }
            if (y) res.emplace_back(p, y);
        }
        if (x > 1) res.emplace_back(x, 1);
        return res;
    }
} sieve(1000000);

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 or m == 1) {
        cout << "YES\n";
        return;
    }
    auto f = sieve.factor(n);
    cout << (m < f[0].first ? "YES\n" : "NO\n");
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