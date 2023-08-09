//https://yjg-lab.tistory.com/188
#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define MAX_V 10010
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using Point = pair<ll, ll>;
int V, E;

int id = 0;
int p[MAX_V];
bool finished[MAX_V] = {0};
vector<int> v[MAX_V];
vector<vector<int>> SCCs;
stack<int> s;

int DFS(int c)
{
    p[c] = ++id; // 정점에 고유 id 부여
    s.push(c);   // 스택에 자신을 삽입

    int parent = p[c];
    for (int nxt : v[c]) {
        if (p[nxt] == 0) { // 아직 방문하지 않은 정점
            parent = min(parent, DFS(nxt));
        } else if (!finished[nxt]) { // 방문은 했으나, 아직 SCC로 묶이지 않은 정점
            parent = min(parent, p[nxt]);
        }
    }

    // 찾은 부모 노드가 자기 자신인 경우, SCC를 찾은 것
    // 자기 자신이 나올 때까지 Stack 에서 pop
    if (parent == p[c]) {
        vector<int> scc;
        while (true) {
            int cur = s.top(); s.pop();
            scc.push_back(cur);
            finished[cur] = true;
            if (cur == c) break;
        }
        sort(scc.begin(), scc.end());
        SCCs.push_back(scc);
    }
    return parent;
}
int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a>>b;
        v[a].push_back(b);
    }

    for (int i = 1; i <= V; ++i) {
        if(p[i] == 0) DFS(i);
    }
    sort(SCCs.begin(), SCCs.end());
    cout << SCCs.size() << endl;
    for (auto& scc : SCCs) {
		for (int num : scc)
			cout << num << " ";
		cout << "-1" << endl;
	}
    return 0;
}