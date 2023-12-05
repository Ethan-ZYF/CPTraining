#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int N, Q;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    const int M = *max_element(A.begin(), A.end()) + 1;

    vector<int> freq(M);
    const int B = sqrtl(N);
    cin >> Q;
    vector<array<int, 4>> query(Q);
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        query[i] = {l, r, x, i};
    }
    sort(query.begin(), query.end(), [&](auto a, auto b) {
        if (a[0] / B != b[0] / B) {
            return a[0] < b[0];
        } else {
            return a[1] < b[1];
        }
    });
    vector<i64> ans(Q);

    auto add = [&](int x) {
        freq[x] += 1;
    };
    auto del = [&](int x) {
        freq[x] -= 1;
    };

    int L = 0, R = 0;
    for (auto [l, r, x, i] : query) {
        while (R < r) {
            add(A[R++]);
        }
        while (L > l) {
            add(A[--L]);
        }
        while (R > r) {
            del(A[--R]);
        }
        while (L < l) {
            del(A[L++]);
        }
        ans[i] = freq[x];
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        solve();
    }

    return 0;
}