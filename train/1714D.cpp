#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <int BASE = 131>
struct StringRollingHash {
    std::vector<i64> hash, base, mod;
    const int P = findPrime(rng() % 900000000 + 20020801);

    StringRollingHash(const std::string& s = "") {
        int n = s.size();
        hash.resize(n + 1);
        base.resize(n + 1);
        mod.resize(n + 1);
        base[0] = 1;
        mod[0] = 1;
        for (int i = 1; i <= n; i++) {
            base[i] = (base[i - 1] * BASE) % P;
            mod[i] = (mod[i - 1] * P) % P;
        }
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * BASE + s[i]) % P;
        }
    }

    i64 get(int l, int r) {
        return (hash[r] - (hash[l] * base[r - l]) % P + P) % P;
    }

    i64 get(const std::string& s) {
        i64 h = 0;
        for (char c : s) {
            h = (h * BASE + c) % P;
        }
        return h;
    }

    bool isprime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int findPrime(int n) {
        while (!isprime(n))
            n++;
        return n;
    }
};

void solve() {
    string t;
    cin >> t;
    int sz = t.size();
    StringRollingHash hash(t);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> hsh(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        hsh[i] = hash.get(s[i]);
    }

    int cur = 0;
    vector<array<int, 2>> ans;
    while (cur < sz) {
        array v{cur, -1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= cur && j + s[i].length() <= sz; j++) {
                if (hash.get(j, j + s[i].length()) == hsh[i]) {
                    v = max(v, array{j + int(s[i].length()), i, j});
                }
            }
        }
        if (v[0] == cur) {
            cout << "-1\n";
            return;
        }
        cur = v[0];
        ans.push_back({v[1], v[2]});
    }

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
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