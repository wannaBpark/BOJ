#include <bits/stdc++.h>
using namespace std;
using ll = long long;
queue<int> q;
int in[100010]={0,};
int to[100010];
int visited[100010]={0,};
int N;
vector<int> ans;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N; 
    for(int i= 1; i<=N; ++i) {
        cin >> to[i];
        in[to[i]]++;
    }
    for(int i= 2; i<=N; ++i) {
        if(!in[i]) {
            q.push(i);
        }
    }
    for (int cur = 1; !visited[cur]; ) {
        visited[cur] = true;
        ans.push_back(cur = to[cur]);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        while(true) {
            ans.push_back(cur);
            if (visited[cur]) break;
            visited[cur] = true; 
            cur = to[cur];
        }
    }
    for (int i =1; i<=N; ++i) {
        if(visited[i]) continue;
        for (int cur = i; ; ) {
            ans.push_back(cur);
            if (visited[cur]) break;
            visited[cur] = true; 
            cur = to[cur];
        }
    }
    int sz = ans.size();
    cout << sz<< '\n';
    for(int i =0; i< sz; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}