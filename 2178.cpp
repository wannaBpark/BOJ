#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int,int>> q;
int visited[101][101] = { 0 };
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };
char A[101][101];
int N, M,ans=0;
int isRange(int x, int y) 
{
	if (x < 0 || y < 0 || x >= N || y >= M) return 0;
	return 1;
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &A[i]);
	}
	q.push({ 0,0 }); visited[0][0] = 1;
	while (!q.empty()) {
		int cur_x = q.front().first; int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int px = cur_x + dx[i], py = cur_y + dy[i];
			if (!isRange(px, py) || visited[px][py]) continue;
			if (A[px][py] == '1')
				q.push({ px,py });
			visited[px][py] = max(visited[cur_x][cur_y] + 1, visited[px][py]);
		}
	}
	printf("%d\n", visited[N-1][M-1]);
	return 0;
}