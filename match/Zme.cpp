#include <bits/stdc++.h>
using namespace std;
// using i64 = int; // AC
using i64 = long long;  //! WA
constexpr int N = 105;
i64 n, W, nums[N][3];

void solve() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }
    vector<vector<i64>> dp(n + 1, vector(W + 1, 0LL));
    // vector<vector<i64>> dp(n + 1, vector(W + 1, 0));
    for (i64 i = 1; i <= n; i++) {
        i64 v = nums[i][0], w = nums[i][1], cnt = nums[i][2];
        map<i64, deque<pair<i64, i64>>> mp;
        for (i64 j = 0; j <= W; j++) {
            // i64 mod = j % w, t = j / w;
            i64 mod = fmod(j, w), t = j / w;
            i64 temp = dp[i - 1][j] - t * v;
            while (!mp[mod].empty() && temp >= mp[mod].back().second)
                mp[mod].pop_back();
            mp[mod].emplace_back(t, temp);
            while (t - mp[mod].front().first > cnt)
                mp[mod].pop_front();
            if (j)
                dp[i][j] = max(dp[i][j - 1], mp[mod].front().second + t * v);
        }
    }
    cout << dp[n][W] << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}