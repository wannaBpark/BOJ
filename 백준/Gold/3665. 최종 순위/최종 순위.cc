#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N,T,M;
vector<int> ans;
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> T;
    while(T--) {
        int in[510]={0,};
        int visited[510]={0,};
        int edge[510][510]={0,};
        int result = 1;
        vector<int> v;
        vector<int> rank;
        queue<int> q;
        cin >> N;
        for (int i =0; i<N; ++i) {
            int a; cin >> a;
            for(auto& from : v) {
                edge[from][a] = true;
                ++in[a];
            }
            v.push_back(a);
        }
        // cout<<'\n';
        cin >> M;
        while(M--){
            int a,b; cin >> a >>b;
            int& edge1 = edge[a][b]; int& edge2 = edge[b][a];
            if (edge1) {
                edge1 = false; edge2 = true;
                ++in[a]; --in[b];
            } else if (edge2) {
                edge2 = false; edge1 = true;
                ++in[b]; --in[a];
            }
        }
        // cout << "in : ";
        for (int i =1; i<=N; ++i) {
            if(!in[i]) q.push(i);
            // cout << in[i] << " ";
        }
        // cout << '\n'; 
        if (q.empty()) {
            cout << "IMPOSSIBLE\n"; continue;
        }
        while(!q.empty()) {
            // cout << "cur: "<<q.front() << '\n';
            if (visited[q.front()]) {
                result = -1; break;
            } else if (q.size() >= 2) {
                result = -2; break;
            } 
            auto cur = q.front(); q.pop();
            visited[cur] = true;
            rank.push_back(cur);
            for(int nxt =1; nxt <= N; ++nxt) {
                if(!edge[cur][nxt]) continue;
                if (--in[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        if (result != true){
            cout << (result == -1 || rank.size() != N) ? "IMPOSSIBLE\n" : "?\n"; 
            continue;
        } else if (rank.size() != N) {
            cout << "IMPOSSIBLE\n"; continue;
        }
        for(auto& r : rank) cout << r << " "; cout << '\n';
    }

    return 0;
}