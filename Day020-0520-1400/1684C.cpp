#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int x = 0;
    while (x < n && is_sorted(a[x].begin(), a[x].end())) {
        x++;
    }

    if (x == n) {
        cout << "1 1\n";
        return;
    }

    auto b = a[x];
    sort(b.begin(), b.end());

    vector<int> p;
    for (int j = 0; j < m; j++) {
        if (a[x][j] != b[j]) {
            p.push_back(j);
        }
    }

    if (p.size() > 2) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        swap(a[i][p[0]], a[i][p[1]]);
        if (!is_sorted(a[i].begin(), a[i].end())) {
            cout << "-1\n";
            return;
        }
    }

    cout << p[0] + 1 << " " << p[1] + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}