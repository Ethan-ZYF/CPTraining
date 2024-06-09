#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(5);
    vector<int> b = a;
    int i = 2;
    b[i] = i++;
    for (int x : b) {
        cout << x << ' ';
    }
    cout << '\n';

    b = a;
    i = 2;
    b[i] = ++i;
    for (int x : b) {
        cout << x << ' ';
    }
    cout << '\n';

    b = a;
    i = 2;
    b[i++] = i;
    for (int x : b) {
        cout << x << ' ';
    }
    cout << '\n';

    b = a;
    i = 2;
    b[++i] = i;
    for (int x : b) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}