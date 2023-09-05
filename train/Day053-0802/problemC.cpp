#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif
vector<int> rm(vector<int> removals, int& n) {
    int sz = removals.size();
    cout << "- " << sz << " ";
    for (int x : removals) {
        cout << x << " ";
    }
    cout << endl;
    n -= sz;
    vector<int> res(n);
    for (auto& x : res) {
        cin >> x;
    }
    return res;
}

bool cmp(map<int, int>& mp1, map<int, int>& mp2) {
    if (mp1.size() != mp2.size()) return false;
    for (auto& [k, v] : mp1) {
        if (mp2[k] != v) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp1, mp2;
    for (auto& x : a) {
        cin >> x;
        mp1[x]++;
    }
    vector<int> b = rm({}, n);
    for (auto& x : b) {
        mp2[x]++;
    }
    if (cmp(mp1, mp2)) {
        b = rm({}, n);
        mp2.clear();
        for (auto& x : b) {
            mp2[x]++;
        }
    }
    int target;
    for (auto& [k, v] : mp2) {
        if (mp1[k] < v) {
            target = k;
            break;
        }
    }
    debug("2 or 3", target);
    vector<int> removals;
    a.clear();
    for (int i = 0; i < n; i++) {
        if (b[i] != target) {
            removals.push_back(i + 1);
        } else {
            a.push_back(b[i]);
        }
    }
    b = rm(removals, n);
    mp1.clear();
    mp2.clear();
    for (auto& x : a) {
        mp1[x]++;
    }
    for (auto& x : b) {
        mp2[x]++;
    }

    if (cmp(mp1, mp2)) {
        b = rm({}, n);
        mp2.clear();
        for (auto& x : b) {
            mp2[x]++;
        }
    }
    target = -1;
    // for (auto& [k, v] : mp2) {
    //     if (mp1[k] < v) {
    //         target = k;
    //         break;
    //     }
    // }
    for (int i = 0; i < n; i++) {
        if (mp1.count(b[i]) == 0) {
            target = i + 1;
            break;
        }
    }
    debug("4 or 5", target);
    cout << "! " << target << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}