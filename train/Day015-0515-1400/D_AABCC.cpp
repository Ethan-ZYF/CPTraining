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
} sieve(5e5);

void solve() {
    i64 n;
    cin >> n;
    i64 ans = 0;
    auto p = sieve.primes;
    int sz = p.size();
    int amax = 260;
    for (int i = 0; i < sz and p[i] <= amax; i++) {
        for (int j = i + 1; j < sz; j++) {
            i64 a = p[i], c = p[j];
            i64 bmax = n / (a * a * c * c);
            int pos = upper_bound(p.begin(), p.end(), bmax) - p.begin() - 1;
            pos = min(pos, j - 1);
            if (pos <= i) continue;
            int b = p[pos];
            ans += pos - i;
        }
    }
    cout << ans << '\n';
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