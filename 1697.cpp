#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;
int N, K, visited[100002] = { 0 }, dist[MAX + 2] = { 0 };
queue<int> q;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &K);
	q.push(N);
	fill(visited, visited + N + 1, MAX);
	visited[N] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == K) break;
		int next[3] = {cur-1,cur+1, cur*2};
		for (int i = 0; i < 3; i++) {
			if (next[i] < 0 || next[i]>100000 || dist[next[i]]) continue;
			//범위 밖(음수,십만이상)이거나, 이미 채워져있으면 스킵
			dist[next[i]] = dist[cur] + 1; //BFS에서 미로문제와 마찬가지로 최단경로일수밖에없다.
			q.push(next[i]);
		}
	}
	for (int i = 0; i <= K; i++) {
		printf("%d %d\n", i,dist[i]);
	}
	puts("");
	printf("%d\n", dist[K]);
	return 0;
}