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
} sieve(4e4);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    map<int, int> cnt;
    for (auto x : a) {
        for (auto p : sieve.primes) {
            if (p * p > x) break;
            if (x % p == 0) {
                cnt[p]++;
                while (x % p == 0)
                    x /= p;
            }
        }
        if (x > 1) cnt[x]++;
    }
    int maxv = ranges::max(cnt | views::values);
    cout << (maxv > 1 ? "YES" : "NO") << '\n';
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