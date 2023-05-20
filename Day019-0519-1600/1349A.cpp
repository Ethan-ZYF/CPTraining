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
} sieve(2e5 + 5);

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    map<i64, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        auto f = factor(a[i]);
        for (auto [p, c] : f) {
            mp[p].push_back(c);
        }
    }
    for (auto& [p, v] : mp) {
        sort(v.begin(), v.end());
    }
    i64 ans = 1;
    for (auto& p : sieve.primes) {
        if (mp.count(p)) {
            auto& v = mp[p];
            if (v.size() < n - 1) continue;
            if (v.size() == n - 1)
                ans *= pow(p, v[0]);
            else
                ans *= pow(p, v[1]);
        }
    }
    cout << ans << "\n";
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