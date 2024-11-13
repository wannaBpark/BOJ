#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int K, N, F, flag = false;
int edge[910][910]={0,};
vector<int> v[910];
int isPromising(vector<int>& arr, int nxt) {
    for (auto& cur : arr) {
        if (!edge[cur][nxt]) return false;
    }
    return true;
}
void backtracking(int idx, vector<int>& arr) {
    if (arr.size() == K) {
        flag = true;
        return;
    }
    if (flag) return;
    for (int nxt = idx+1; nxt <= N; ++nxt) {
        if (!isPromising(arr, nxt)) continue;
        arr.push_back(nxt);
        backtracking(nxt, arr);
        if (flag) return;
        arr.pop_back();
    }
}
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> K >> N >> F;
    for (int i =0; i<F; ++i) {
        int a,b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
        edge[a][b] = edge[b][a] = true;
    }
    vector<int> ans;
    backtracking(0, ans);
    if (!flag) {
        cout << "-1";
        return 0;
    }
    for(auto& num : ans) {
        cout << num << '\n';
    }
    return 0;
}