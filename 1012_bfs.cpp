#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
int N, M;
int A[52][52];
int visited[52][52];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int isRange(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return 0;
	return 1;
}
void bfs()
{
	int x, y,py,px;
	while (!q.empty()) {
		y = q.front().first; x = q.front().second; q.pop();
		visited[y][x] = true;

		for (int i = 0; i < 4; i++) {
			py = y + dy[i],px = x+dx[i];

			if (isRange(py, px) && !visited[py][px] && A[py][px] == 1) {
				q.push({ py,px });
				visited[py][px] = true;
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int T,K,a,b;
	scanf("%d", &T);
	while (T--) {
		int ans=0;
		scanf("%d%d%d", &M, &N, &K);
		fill(*A, *A +52*52, 0);
		fill(*visited, *visited + 52*52, 0);
		while (K--) scanf("%d%d", &a, &b), A[b][a] = 1;
		for(int i=0; i<N; i++)
			for (int j = 0; j < M; j++)
				if (A[i][j] == 1 && !visited[i][j]) {
					q.push({ i,j });
					bfs(); ++ans;
					//printf("%d %d\n", i, j);
				}
		printf("%d\n", ans);
	}
	
	
	return 0;
}