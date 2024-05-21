#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct StringHelper {
    std::string s;
    std::vector<int> sa, lcp, z;

    StringHelper(const std::string& s) : s(s) {
        sa = suffix_array(s);
        lcp = lcp_array(s, sa);
        z = z_algorithm(s);
    }

    std::vector<int> suffix_array(const std::string& s) {
        int n = s.size();
        std::vector<int> sa(n), rnk(s.begin(), s.end()), tmp(n);
        std::iota(sa.begin(), sa.end(), 0);
        for (int k = 1; k < n; k *= 2) {
            auto cmp = [&](int x, int y) {
                if (rnk[x] != rnk[y]) return rnk[x] < rnk[y];
                int rx = x + k < n ? rnk[x + k] : -1;
                int ry = y + k < n ? rnk[y + k] : -1;
                return rx < ry;
            };
            std::sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }
            std::swap(tmp, rnk);
        }
        return sa;
    }

    std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
        int n = s.size();
        assert(n >= 1);
        std::vector<int> rnk(n);
        for (int i = 0; i < n; i++) {
            rnk[sa[i]] = i;
        }
        std::vector<int> lcp(n - 1);
        int h = 0;
        for (int i = 0; i < n; i++) {
            if (h > 0) h--;
            if (rnk[i] == 0) continue;
            int j = sa[rnk[i] - 1];
            for (; j + h < n && i + h < n; h++) {
                if (s[j + h] != s[i + h]) break;
            }
            lcp[rnk[i] - 1] = h;
        }
        return lcp;
    }

    std::vector<int> z_algorithm(const std::string& s) {
        int n = s.size();
        if (n == 0) return {};
        std::vector<int> z(n);
        z[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            int& k = z[i];
            k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
            while (i + k < n && s[k] == s[i + k])
                k++;
            if (j + z[j] < i + z[i]) j = i;
        }
        z[0] = n;
        return z;
    }
};

void solve() {
    string s;
    cin >> s;
    StringHelper helper(s);
    int n = s.size();
    auto z = helper.z;
    auto z2 = z;
    sort(z2.begin(), z2.end());
    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (z[i] == n - i) {
            int j = lower_bound(z2.begin(), z2.end(), n - i) - z2.begin();
            debug(j);
            ans.emplace_back(n - i, n - j);
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}