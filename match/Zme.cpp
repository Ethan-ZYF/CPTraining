#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> tmparr(n);
    for(int i=0; i<n; ++i){
        cin >> tmparr[i];
    }
    auto f = [&](){
        map<int, int> Map;
        for(int i=0; i<(int)tmparr.size(); ++i){
            Map[tmparr[i]] = i;
        }
        vector<int> ret;
        for(auto &[k, v]: Map){
            ret.emplace_back(v);
        }
        return ret;
    };

    vector<int> pos = f();

    map<int, int> Map;
    vector<int> sortedpos = pos;
    sort(sortedpos.begin(), sortedpos.end());
    for(int i=0; i<sortedpos.size(); ++i){
        Map[sortedpos[i]] = i;
    }
    int cnt = 0;
    for(int i=0; i<pos.size(); ++i){
        if(pos[i] == sortedpos[i]){
            continue;
        }
        swap(pos[i], pos[Map[pos[i]]]);
        ++cnt;
    }
    cout << cnt;
    return 0;
}