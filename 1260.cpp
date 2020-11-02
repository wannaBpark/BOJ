#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int N, M, V;
int visited[1001];
vector<int> v[1001];
queue<int> q;
void dfs(int s)
{
	visited[s] = 1; 
	printf("%d ", s);
	for (int i = 0; i < v[s].size(); i++) {
		int next = v[s][i];
		if(visited[next] == 0)
			dfs(next);
	}
	
}
void bfs()
{
	int cur;
	
	while (!q.empty()) {
		cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]]) continue;
			else {
				q.push(v[cur][i]);
				visited[v[cur][i]] = 1;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b;
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	visited[V] = 1;
	dfs(V);

	printf("\n");
	fill(visited, visited + N + 1, 0);
	q.push(V); visited[V] = 1;
	bfs();
	return 0;
}