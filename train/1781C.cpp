#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) pos[(int)(s[i] - 'a')].push_back(i);

    vector<int> freqSort(26);
    iota(freqSort.begin(), freqSort.end(), 0);
    sort(freqSort.begin(), freqSort.end(), [&](int i, int j) {
        return pos[i].size() > pos[j].size();
    });

    int best = -1;
    string ret = "------";

    for (int m = 1; m <= 26; m++) {
        if (n % m) continue;

        int count = 0;
        for (int i = 0; i < m; i++) {
            count += min(n / m, (int)pos[freqSort[i]].size());
        }
        if (count > best) {
            best = count;
            ret = string(n, ' ');
            vector<char> extra;
            for (int i = 0; i < m; i++) {
                int at = freqSort[i];
                for (int j = 0; j < n / m; j++) {
                    if (j < (int)pos[at].size()) {
                        ret[pos[at][j]] = (char)('a' + at);
                    } else {
                        extra.push_back((char)('a' + at));
                    }
                }
            }

            for (char& c : ret) {
                if (c == ' ') {
                    c = extra.back();
                    extra.pop_back();
                }
            }
        }
    }

    cout << n - best << "\n";
    cout << ret << "\n";
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