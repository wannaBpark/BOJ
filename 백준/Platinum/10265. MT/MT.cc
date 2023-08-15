//https://yjg-lab.tistory.com/188
#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define MAX_V 1010
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
int N, K;

int cnt = 0;
int id = 0;
int sz_components;
int p[MAX_V];
int scc_num[MAX_V];
int indegree[MAX_V];
bool finished[MAX_V] = {0};
bool visited[MAX_V] = {0};
vector<int> v[MAX_V];
vector<vector<int>> SCCs;
stack<int> s;
vector<int> vsize;
int dp[MAX_V][MAX_V] = {0};
vector<pii> components;

int solve(int cur, int k);
void calculate_indegree(int scc, int cur);

int tarjan_scc(int c)
{
    p[c] = ++id; // 정점에 고유 id 부여
    s.push(c);   // 스택에 자신을 삽입

    int parent = p[c];
    for (int nxt : v[c]) {
        if (scc_num[nxt] != -1) {
            // 해당 scc의 indegree ++
            // indegree[scc_num[nxt]]++;
        }
        if (p[nxt] == 0) { // 아직 방문하지 않은 정점
            parent = min(parent, tarjan_scc(nxt));
        } else if (!finished[nxt]) { // 방문은 했으나, 아직 SCC로 묶이지 않은 정점
            parent = min(parent, p[nxt]);
        }
    }
    // 찾은 부모 노드가 자기 자신인 경우, SCC를 찾은 것
    // 자기 자신이 나올 때까지 Stack 에서 pop
    if (parent == p[c]) {
        ++cnt; 
        vector<int> scc;
        while (true) {
            int cur = s.top(); s.pop();
            scc.push_back(cur);
            finished[cur] = true;
            scc_num[cur] = cnt;
            if (cur == c) break;
        }
        sort(scc.begin(), scc.end());
        SCCs.push_back(scc);
    }
    return parent;
}

int DFS(int cur) 
{
    int ret = 0;

    if (visited[cur] == true) return 0;

    visited[cur] = true;
    ret++;
    for (auto nxt : v[cur]) {
        ret += DFS(nxt); 
    }

    return ret;
}
int main()
{
    fastio;
    fill(scc_num, scc_num + MAX_V, -1);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a;
        // v[i].push_back(a);
        v[a].push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        if(p[i] == 0) tarjan_scc(i);
    }
    for (int i = 1; i <= N; ++i) {
        if (visited[i] == 0) {
            calculate_indegree(scc_num[i], i);
        }
    }
    //cout << endl;
    // sort(SCCs.begin(), SCCs.end());

    fill(visited, visited + MAX_V, 0);

    for (int i = 0; i < SCCs.size(); ++i) {
        int cur_scc_start = SCCs[i][0];
        int cur_scc = scc_num[cur_scc_start];
        if (visited[cur_scc_start] == 0 && indegree[cur_scc] == 0) {
            // cout << "DFS for "<< SCCs[i][0] << endl;
            pii p;
            p.first = SCCs[i].size();
            p.second = DFS(SCCs[i][0]);

            components.push_back(p);
        }
    }
    sort(components.begin(), components.end());
    // cout << "Components" << endl;
    // for (auto p : components) {
    //     cout << p.first << " " << p.second << endl;
    // }
    memset(dp, -1, sizeof(dp));
    sz_components = components.size();

    solve(0, K);
    cout << dp[0][K] << endl;
    // cout << SCCs.size() << endl;
    // for (auto& scc : SCCs) {
    //     vsize.push_back(scc.size());
    //     cout << "indegree " << indegree[scc_num[scc[0]]] << endl;
	// 	for (int num : scc)
	// 		cout << num << " ";
	// 	cout << "-1" << endl;
	// }
    
    // vsize.push_back(0);
    // sort(vsize.begin(), vsize.end());
    // int ans = 0;
    // int sz = vsize.size();
    // for (int i = 1; i <= sz; ++i) {
    //     for (int w = 0; w <= K; ++w) {
    //         if (w < vsize[i]) {
    //             dp[i][w] = dp[i-1][w];
    //         } else {
    //             dp[i][w] = max(dp[i-1][w], dp[i-1][w-vsize[i]] + vsize[i]);
    //         }
    //         ans = max(ans, dp[i][w]);
    //     }
        
    // }

    // cout << ans;
    // cout << endl << "id : " << cnt << endl;
    return 0;
}


// int n;
// pair<int, int> component[1000];
// int dp[1000][1000];

void calculate_indegree(int scc, int cur)
{
    if (visited[cur] == true) return;
    visited[cur] = true; 
    for (auto nxt : v[cur]) {
        if (scc_num[nxt] != scc) {
            // 내 SCC와 다른 SCC를 가리킬 때, indegree++
            indegree[scc_num[nxt]]++;
        }
        calculate_indegree(scc_num[nxt], nxt);
    }
}
int solve(int cur, int k) // cur ~ sz_components - 1    k명   최대 인원수
{
    int& ret = dp[cur][k];

    if (ret != -1)
        return ret;
    if (cur >= sz_components)
        return 0;
    if (k <= 0)
        return 0;

    // component[cur]에서   아무도 안데려가는 경우
    ret = solve(cur + 1, k);
    for (int i = components[cur].first; i <= components[cur].second; i++) {
        if (i <= k) {
            ret = max(ret, i + solve(cur + 1, k - i));
        }
    }
    return ret;
}