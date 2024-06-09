#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

map<i64, int> factor(i64 n) {
    map<i64, int> res;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res[i] = 0;
            while (n % i == 0) {
                res[i]++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        res[n] = 1;
    }
    return res;
}

map<i64, int> mpadd(map<i64, int> a, map<i64, int> b) {
    for (auto [k, v] : b) {
        a[k] += v;
    }
    return a;
}

class Solution {
   public:
    string clearStars(string s) {
        int n = s.size();
        set<int> rm;
        vector<priority_queue<int>> pos(26);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!pos[j].empty()) {
                        rm.insert(pos[j].top());
                        pos[j].pop();
                        break;
                    }
                }
            } else {
                pos[s[i] - 'a'].push(i);
            }
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                if (!rm.count(i)) {
                    res.push_back(s[i]);
                }
            }
        }
        return res;
    }
};

int main() {

    Solution sol;
    // nums1 = [1, 2, 4, 12], nums2 = [2, 4], k = 3
    vector<int> nums1 = {1, 2, 4, 12}, nums2 = {2, 4};
    int k = 3;
    cout << sol.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}