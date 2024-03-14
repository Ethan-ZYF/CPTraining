#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

using i64 = long long;
constexpr int OFFSET[6] = {7, 9, 21, 33, 87, 93};
constexpr int BASE = 131;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
i64 P = 1e9 + OFFSET[rng() % 6];

struct StringRollingHash {
    std::vector<i64> hash, base, mod;

    StringRollingHash(const std::string& s) {
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
};

class Solution {
   public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        map<i64, int> cnt;
        i64 ans = 0;
        reverse(words.begin(), words.end());
        for (auto& s : words) {
            StringRollingHash srh(s);
            debug(P);
            int len = s.size();
            i64 h = srh.get(s);
            debug(s, h);
            ans += cnt[h];

            for (int i = 0; i < len; i++) {
                i64 h1 = srh.get(0, i + 1);
                int j = len - i - 1;
                i64 h2 = srh.get(j, len);
                if (h1 == h2) {
                    debug(s, s.substr(0, i + 1), s.substr(j, i + 1));
                    cnt[h1]++;
                }
            }
            debug(cnt);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // words = ["a","aba","ababa","aa"]
    vector<string> words = {"a", "aba", "ababa", "aa"};
    cout << sol.countPrefixSuffixPairs(words) << endl;
    return 0;
}