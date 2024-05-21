#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 65535;
constexpr int MOD = 1e9 + 7;
using Ret = array<i64, N>;
constexpr Ret f{[]() -> Ret {
    Ret fac{};
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    return fac;
}()};
constexpr Ret inv{[]() -> Ret {
    Ret inv{};
    inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    return inv;
}()};

i64 C(int n, int m) {
    if (n < m) {
        return 0;
    }
    return f[n] * inv[m] % MOD * inv[n - m] % MOD;
}

class Solution {
   public:
    int waysToReachStair(int k) {
        int ans = 0;
        int cur = 1;
        for (int i = 0; i < 30; i++) {
            int diff = cur - k;
            if (diff <= i + 1 && diff >= 0) {
                ans += C[i + 1][diff];
            }
            cur += 1 << i;
        }
        return ans;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    static_assert(C[5][2] == 10);
    static_assert(C[5][5] == 1);
    static_assert(C[5][0] == 2);
    return 0;
}