#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

char s[10001];
class Solution {
   public:
    int maxTotalReward(vector<int>& a) {
        sort(a.begin(), a.end());
        memset(s, 0, sizeof(s));
        int m = a.back() * 2;
        s[0] = 1;
        for (int x : a) {
            for (int i = x; i < 2 * x; i++) {
                s[i] |= s[i - x];
            }
        }
        int i;
        for (i = m; i >= 0; i--)
            if (s[i]) break;
        return i;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution sol;
    // rewardValues = [1,1,3,3]
    vector<int> rewardValues = {1, 1, 3, 3};
    // cout << sol.maxTotalReward(rewardValues) << endl;
    rewardValues = {1, 6, 4, 3, 2};
    // cout << sol.maxTotalReward(rewardValues) << endl;
    // [3,14,12] 26
    rewardValues = {3, 14, 12};
    // cout << sol.maxTotalReward(rewardValues) << endl;
    // [6,17,10,13]
    rewardValues = {6, 17, 10, 13};
    cout << sol.maxTotalReward(rewardValues) << endl;

    return 0;
}