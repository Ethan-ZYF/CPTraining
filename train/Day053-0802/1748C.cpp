#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

std::unordered_map<long long, int, custom_hash> ump;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<i64>> pref;
    vector<i64> before;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ok = true;
        }
        if (ok) {
            if (a[i] == 0) {
                pref.push_back({0});
            } else {
                pref.back().push_back(a[i]);
            }
        }else{
            before.push_back(a[i]);
        }
    }
    int ans = 0;
    i64 tot = 0;
    for (auto& x : before) {
        tot += x;
        if (tot == 0) ans++;
    }
    debug(pref);
    for (auto& v : pref) {
        i64 sum = 0;
        int mx = 1;
        ump.clear();
        for (auto& x : v) {
            sum += x;
            ump[sum]++;
            mx = max(mx, ump[sum]);
        }
        debug(v, mx);
        ans += mx;
    }
    cout << ans << endl;
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