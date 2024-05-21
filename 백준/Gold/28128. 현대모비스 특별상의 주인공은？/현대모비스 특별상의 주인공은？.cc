#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<string> v[3010];

set<string> ans;
int N, M;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            string s;
            cin >> s;
            v[i].push_back(s);
        }
    }
    
    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] == v[i+1][j]) ans.insert(v[i][j]);
        }
    }
    for (int i = 0; i < N-2; ++i) {
        for (int j = 0; j <M; ++j) {
            if (v[i][j] == v[i+2][j]) ans.insert(v[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M-1; ++j) {
            if (v[i][j] == v[i][j+1]) ans.insert(v[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M-2; ++j) {
            if (v[i][j] == v[i][j+2]) ans.insert(v[i][j]);
        }
    }
    if (ans.size() == 0) puts("MANIPULATED");
    else {
        for (auto i : ans) {
            cout << i << '\n';
        }
    }
    return 0;
}