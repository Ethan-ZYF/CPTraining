#include <bits/stdc++.h>

#define int long long

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void NanYan() {
    std::unordered_map<int, int, custom_hash> a;
    std::map<int, bool> b;
    int n, ans = 0;
    std::cin >> n;
    std::set<int> st;
    while (n--) {
        int x;
        std::cin >> x;
        a[x]++;
        st.insert(x);
    }

    for (auto x : st) {
        if (!b[x]) {
            b[x] = true;
            ans += a[x] * (a[x] - 1) * (a[x] - 2);
            for (int j = 2; j * j <= x; ++j) {
                if (x % (j * j) == 0) {  //真难则反
                    ans += a[x] * a[x / j] * a[x / j / j];
                }
            }
        }
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_--) {
        NanYan();
    }

    return 0;
}