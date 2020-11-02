#include <cstdio>

int graph[1009][1009] = { 0 }, visited[1009] = { 0 };
int V, E, start;

void dfs(int node) {
	visited[node] = 1;
	printf("%d ", node);

	for (int i = 1; i <= V; i++) {
		if (graph[node][i] == 1 && visited[i]==0) {
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d %d %d", &V, &E, &start);

	for (int i = 0; i < E; i++) {
		int a, b;	
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(start);

	return 0;
}