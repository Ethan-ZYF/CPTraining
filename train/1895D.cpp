#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

template <typename T = int>
struct Trie {
    struct Node {
        array<Node *, 2> children{};
        int cnt = 0;
    };

    int HIGH_BIT;
    Trie(int HIGH_BIT = 25) : HIGH_BIT(HIGH_BIT) {}

    Node *root = new Node();

    void insert(T val) {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; i--) {
            T bit = (val >> i) & 1;
            if (cur->children[bit] == nullptr) {
                cur->children[bit] = new Node();
            }
            cur = cur->children[bit];
            cur->cnt++;
        }
    }

    void remove(T val) {
        Node *cur = root;
        for (int i = HIGH_BIT; i >= 0; i--) {
            cur = cur->children[(val >> i) & 1];
            cur->cnt--;
        }
    }

    T max_xor(T val) {
        Node *cur = root;
        T ans = 0;
        for (int i = HIGH_BIT; i >= 0; i--) {
            T bit = (val >> i) & 1;
            if (cur->children[bit ^ 1] && cur->children[bit ^ 1]->cnt) {
                ans |= 1 << i;
                bit ^= 1;
            }
            cur = cur->children[bit];
        }
        return ans;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1), ps(n - 1);
    for (auto& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), ps.begin(), bit_xor<int>());
    Trie t{};
    for (int i = 0; i < n - 1; i++) {
        t.insert(ps[i]);
    }
    int begin = -1;
    for (int i = 0; i <= n - 1; i++) {
        int x = t.max_xor(i);
        if(x <= n - 1){
            begin = i;
            break;
        }
    }
    assert(begin != -1);
    vector<int> ans(n);
    ans[0] = begin;
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] ^ a[i - 1];
    }
    for (auto& x : ans) cout << x << " ";
    cout << "\n";
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