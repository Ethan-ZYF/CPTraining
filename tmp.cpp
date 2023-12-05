#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

struct Trie {
    static constexpr int ALPHABET = 26;

    struct Node {
        std::array<Node*, ALPHABET> next;
        bool is_end;
        int cnt;
        Node() : next(), is_end(false), cnt(0) {}
        constexpr int f(char c) {
            // modify this function and ALPHABET to support more characters
            if (c >= 'a' && c <= 'z') {
                return c - 'a';
            } else if (c >= 'A' && c <= 'Z') {
                return c - 'A';
            }
            assert(false);
        }
        Node*& operator[](char x) {
            return next[f(x)];
        }
    };

    Node* root;
    Trie() : root(new Node()) {}

    void add(const std::string& s) {
        Node* p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                (*p)[x] = new Node();
            }
            p = (*p)[x];
            p->cnt++;
        }
        p->is_end = true;
    }

    int count(const std::string& s) {
        Node* p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                return 0;
            }
            p = (*p)[x];
        }
        return p->cnt;
    }

    bool find(const std::string& s) {
        Node* p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                return false;
            }
            p = (*p)[x];
        }
        return p->is_end;
    }
};

class Solution {
   public:
    int countCompleteSubstrings(string s, int k) {
        int n = s.size();
        int res = 0;
        auto get = [&](int t) -> int {
            int ans = 0;
            if (t * k > n)
                return 0;
            int l = 0;
            vector<int> cnt(26, 0);
            int nk = 0;
            auto add = [&](char c) -> void {
                cnt[c - 'a']++;
                if (cnt[c - 'a'] == k + 1)
                    nk--;
                else if (cnt[c - 'a'] == k)
                    nk++;
            };
            auto remove = [&](char c) -> void {
                cnt[c - 'a']--;
                if (cnt[c - 'a'] == k - 1)
                    nk--;
                else if (cnt[c - 'a'] == k)
                    nk++;
            };
            for (int r = 0; r < n; ++r) {
                add(s[r]);
                if (r > 0 && abs(s[r] - s[r - 1]) > 2) {
                    while (l < r) {
                        remove(s[l]);
                        l++;
                    }
                }
                if (r - l + 1 > k * t) {
                    remove(s[l]);
                    l++;
                }
                if (r - l + 1 == k * t && nk == t) {
                    ans++;
                }
            }
            return ans;
        };
        for (int i = 1; i <= 26; ++i)
            res += get(i);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aaabbbccc";
    debug(s);
    int k = 3;
    cout << sol.countCompleteSubstrings(s, k) << endl;
    return 0;
}