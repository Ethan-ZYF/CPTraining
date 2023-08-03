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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (int i = n; i > 0; i--) {
        auto [lx, li] = a[l];
        auto [rx, ri] = a[r];
        if(lx == 0){
            ans[li] = -i;
            l++;
        }else if(rx == i){
            ans[ri] = i;
            r--;
        }else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
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