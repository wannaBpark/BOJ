#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int s, e, N,M;
int visited[101] = { 0 };
vector<int> v[101];
queue<int> q;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d%d", &s, &e);
	scanf("%d", &M);
	int a, b;
	while (M--) {
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b), v[b].emplace_back(a);
	} 
	q.push(s); visited[s] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == e) break;
		for (int i = 0; i < v[cur].size(); i++) {
			if (!visited[v[cur][i]]) q.push(v[cur][i]), visited[v[cur][i]] =visited[cur]+1;
		}
	}
	printf("%d\n", !visited[e] ? -1 : visited[e]);
	return 0;
}