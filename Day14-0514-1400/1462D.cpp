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
    int sum = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i++){
        if(sum % (n - i) != 0)continue;
        int target = sum / (n - i);
        debug(i, target);
        int cur = 0;
        bool ok = true;
        for (int j = 0; j < n; j++){
            cur += a[j];
            if(cur > target){
                ok = false;
                break;
            }
            if(cur == target){
                cur = 0;
            }
        }
        if(cur != 0)ok = false;
        if(ok){
            cout << i << '\n';
            return;
        }
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