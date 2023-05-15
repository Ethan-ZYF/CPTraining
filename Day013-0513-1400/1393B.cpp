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
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    map<int, int> cnt;
    for (auto x : a) cnt[x]++;
    debug(cnt);
    int cnt2 = 0, cnt4 = 0;
    for (auto [x, c] : cnt) {
        cnt2 += c / 2;
        cnt4 += c / 4;
    }
    int q;
    cin >> q;
    while(q--){
        char op;
        int x;
        cin >> op >> x;
        if(op == '+'){
            cnt2 -= cnt[x] / 2;
            cnt4 -= cnt[x] / 4;
            cnt[x]++;
            cnt2 += cnt[x] / 2;
            cnt4 += cnt[x] / 4;
        }else{
            cnt2 -= cnt[x] / 2;
            cnt4 -= cnt[x] / 4;
            cnt[x]--;
            cnt2 += cnt[x] / 2;
            cnt4 += cnt[x] / 4;
        }
        debug(cnt2, cnt4);
        if(cnt4 >= 1 and cnt2 >= 4){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        debug(Task);
        solve();
    }

    return 0;
}