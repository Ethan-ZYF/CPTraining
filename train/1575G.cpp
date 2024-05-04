#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template <i64 P>
struct MLong {
    i64 x;

    constexpr MLong() : x{} {}

    constexpr MLong(i64 x) : x{norm(x % getMod())} {}

    static i64 Mod;

    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }

    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr i64 val() const {
        return x;
    }

    explicit constexpr operator i64() const {
        return x;
    }

    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MLong& operator*=(MLong rhs) & {
        x = mul(x, rhs.x, getMod());
        return *this;
    }

    constexpr MLong& operator+=(MLong rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MLong& operator-=(MLong rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MLong& operator/=(MLong rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
i64 MLong<0LL>::Mod = 1;

template <int P>
struct MInt {
    int x;

    constexpr MInt() : x{} {}

    constexpr MInt(i64 x) : x{norm(x % getMod())} {}

    static int Mod;

    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }

    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }

    constexpr int val() const {
        return x;
    }

    explicit constexpr operator int() const {
        return x;
    }

    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }

    constexpr MInt& operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }

    constexpr MInt& operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr MInt& operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr MInt& operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }

    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }

    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }

    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }

    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
        return os << a.val();
    }

    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
int MInt<0>::Mod = 1;

template <int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

string to_string(Z x) {
    return to_string(x.val());
}

constexpr int mxn = 1e5 + 5;

template <int n>
struct EulerTotient {
    vector<int> phi;

    EulerTotient() : phi(n + 1) {
        iota(phi.begin(), phi.end(), 0);
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i)
                    phi[j] -= phi[j] / i;
            }
        }
    }

    int operator[](int x) const {
        if (x <= n)
            return phi[x];
        int result = x;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0)
                    x /= i;
                result -= result / i;
            }
        }
        if (x > 1)
            result -= result / x;
        return result;
    }
};

EulerTotient<mxn> phi;

template <int n>
struct Divisors {
    vector<vector<int>> d;

    Divisors() : d(n) {
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j += i) {
                d[j].push_back(i);
            }
        }
    }

    const vector<int>& operator[](int x) const {
        return d[x];
    }
};

Divisors<mxn> divs;

vector<int> cnt(mxn);

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    Z ans = 0;
    for (int x = 1; x <= n; x += 1) {
        for (int i = x; i <= n; i += x) {
            int v = a[i - 1];
            for (int y : divs[v]) {
                cnt[y] += 1;
            }
        }
        for (int i = x; i <= n; i += x) {
            int v = a[i - 1];
            for (int y : divs[v]) {
                if (cnt[y]) {
                    ans += Z(phi[x]) * phi[y] * cnt[y] * cnt[y];
                    cnt[y] = 0;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}