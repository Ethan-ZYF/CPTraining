#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

constexpr i64 mod = 998244353;

i64 totalStrength(vector<i64>& strength) {

    i64 n = strength.size();
    vector<i64> left(n, -1);  // left[i] 为左侧严格小于 strength[i] 的最近元素位置（不存在时为 -1）
    vector<i64> right(n, n);  // right[i] 为右侧小于等于 strength[i] 的最近元素位置（不存在时为 n）
    stack<i64> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && strength[st.top()] >= strength[i]) {
            right[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
            left[i] = st.top();
        st.push(i);
    }
    debug(1, left, right);
    i64 s = 0L;             // 前缀和
    vector<i64> ss(n + 2);  // 前缀和的前缀和
    for (int i = 1; i <= n; ++i) {
        s += strength[i - 1];
        ss[i + 1] = (ss[i] + s) % mod;  // 注意取模后，下面计算两个 ss 相减，结果可能为负
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 l = left[i] + 1, r = right[i] - 1;  // [l,r] 左闭右闭
        i64 tot = ((i - l + 1) * (ss[r + 2] - ss[i + 1]) - (r - i + 1) * (ss[i + 1] - ss[l])) % mod;
        ans = (ans + strength[i] * tot) % mod;  // 累加贡献
    }
    return (ans + mod) % mod;  // 防止算出负数
}

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (i64& x : a)
        cin >> x;
    auto b = a;
    for (i64& x : b)
        x = -x;
    i64 mx = totalStrength(b), mn = totalStrength(a);
    cout << ((mx - mn) % mod + mod) % mod << '\n';
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