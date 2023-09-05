#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

bool is_subsequence(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    return j == m;
}

bool is_anagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool is_both(const string &s, const string &t) {
    map<char, int> cnt1, cnt2;
    for (char c : s)
        cnt1[c]++;
    for (char c : t)
        cnt2[c]++;
    for (auto [c, cnt] : cnt2) {
        if (cnt1[c] < cnt)
            return false;
    }
    return true;
}

void solve() {
    string s, t;
    cin >> s >> t;
    if (is_subsequence(s, t)) {
        cout << "automaton\n";
    } else if (is_anagram(s, t)) {
        cout << "array\n";
    } else if (is_both(s, t)) {
        cout << "both\n";
    } else {
        cout << "need tree\n";
    }
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