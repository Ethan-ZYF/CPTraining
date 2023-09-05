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
        std::array<Node *, ALPHABET> next;
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
        Node *&operator[](char x) {
            return next[f(x)];
        }
    };

    Node *root;
    Trie() : root(new Node()) {}

    void add(const std::string &s) {
        Node *p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                (*p)[x] = new Node();
            }
            p = (*p)[x];
            p->cnt++;
        }
        p->is_end = true;
    }

    int count(const std::string &s) {
        Node *p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                return 0;
            }
            p = (*p)[x];
        }
        return p->cnt;
    }

    bool find(const std::string &s) {
        Node *p = root;
        for (auto x : s) {
            if ((*p)[x] == nullptr) {
                return false;
            }
            p = (*p)[x];
        }
        return p->is_end;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Trie trie;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.add(s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << trie.count(s) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}