#include <bits/stdc++.h>
using namespace std;

int ans = 0, books;

void solve(map<int, vector<int>> v, vector<int> time, int cnt) {
    int n = v.size();
    if(books==cnt)
        return;
    unordered_map<int, int> dependents;
    for(auto i: v) {
        vector<int> b = i.second;
        for(auto j: b)
            dependents[j]=1;
    }
    vector<int> independents;
    for(auto i: v) {
        int a = i.first;
        if(dependents.find(a) == dependents.end())
            independents.push_back(a);
    }
    for(auto x: independents) {
        ans+=time[x-1];
    }
    for(auto x: independents) {
        v.erase(x);
    }
    solve(v, time, cnt);
}

int main() {

    int n;
    cin >> n;
    books = n;
    int t;
    cin >> t;
    map<int, vector<int>> v;
    vector<int> time(n, 0);
    for(int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 0; i < n; i++) {
        cin >> time[i];
    }

    solve(v, time, n);

    cout << ans << endl;

}